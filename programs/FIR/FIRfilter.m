%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                    %
%  Linear Phase Filter               %
%                                    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear all; close all;

N = 61; % order of FIR filter
Fs = 48000;
Fp = 1500;
Fsby2 = Fs/2;
Rs = 40; %dB
Rp = 1; %dB
t = 0:1/Fs:240/Fs;

wp = Fp/(48000/2);

fdco = 1.5*Fp;
%fst=Fp*1.6;
fst = 3500;

Fpass = [0 Fp Fp];
Rpass = [-Rp -Rp -Rs];

Fstop = [fst fst Fsby2];
Rstop = [-Rp -Rs -Rs];

ws = fdco/Fsby2; %vector of stop band frequencies 

% win = window(@hann,N+1);
win = window(@hamming,N+1);
b3 = fir1(N, ws,win); %creae filter coefficients

% rounded for integer math on the board
b3Good = round(b3*32767);

str = sprintf('int16_t data[] = \n{');

for i = 1:16:length(b3Good)
    strln = sprintf('%6d, ', b3Good(i:min(i+15,length(b3Good))));
    str = [str sprintf('\n    ') strln];
end
str = [str(1:end-1) sprintf('\n};')];
clipboard('copy', str);


[H3,w3] = freqz(b3,1,2^16,Fs); % generate freqeuency response

% plot filter resopnse
plot(w3, 20*log10(abs(H3)), 'b' ...
    ,Fpass,Rpass,'r--',...
    Fstop,Rstop,'r','LineWidth',2)
axis([0 8000 -2*Rs,5])
grid
xlabel('Frequency (Hz)')
ylabel('Magnitude in dB')
title('FIR Magnitude')


% COMPARING A MATLAB SIGNAL FILTERED TO THE ACTUAL DSP FIR
% datOutput(singed) file. Done on 2/19/23 :)
xbad = sin(2*pi*1000*t) + sin(2*pi*4000*t);
y = filter(b3Good, 1, xbad);

% data from the DSP filter
y_struct = importdata('datOutput(singedint).dat', '', 1);
y_CC15 = y_struct.data;


figure
subplot(2,1,1)
plot(y)
title('Matlab test output')
xlabel('samples')
ylabel('magnitude')

subplot(2,1,2)
plot(y_CC15);
title('Data from the DSP board')
xlabel('samples')
ylabel('magnitude')

% Messi
y_MSE = mean((y(1:240) - y_CC15').^2, 'all');






% %plot phase response
% pause
% plot(w3, angle(H3),'LineWidth',2)
% xlabel('frequency')
% ylabel('Phase (radians)')
% title('Linear Phase Phase')
% axis([0 1 -3 3])
% grid
% pause
% 
% %plot Group Delay
% [grpL,wg] = grpdelay(b3,1,N);
% plot(wg, grpL,'LineWidth',2)
% xlabel('frequency')
% ylabel('Group Delay (Samples)')
% title('Linear Group Delay')