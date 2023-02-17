%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                    %
%  Linear Phase Filter               %
%                                    %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

N = 61; % order of FIR filter
Fs = 48000;
Fp = 1500;
Fsby2 = Fs/2;
Rs = 40; %dB
Rp = 1; %dB

wp = Fp/(48000/2);

fdco = 1.5*Fp;
%fst=Fp*1.6;
fst = 3500;

Fpass = [0 Fp Fp];
Rpass = [-Rp -Rp -Rs];

Fstop = [fst fst Fsby2];
Rstop = [-Rp -Rs -Rs];

ws = fdco/Fsby2; %vector of stop band frequencies 

win = window(@hann,N+1);

b3 = fir1(N, ws,win); %creae filter coefficients
b3Good = round(b3*32767);

[H3,w3] = freqz(b3,1,2^16,Fs); % generate freqeuency response

% plot filter resopnse
plot(w3, 20*log10(abs(H3)), 'b' ...
    ,Fpass,Rpass,'r--',...
    Fstop,Rstop,'r','LineWidth',2)
axis([0 8000 -2*Rs,5])
grid
xlabel('Matlab normalized freq.')
ylabel('Magnitude in dB')
title('FIR Magnitude')

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