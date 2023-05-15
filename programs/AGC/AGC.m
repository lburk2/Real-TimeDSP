BUFF_SIZE = 200;
MAX_GAIN = 10;
MIN_GAIN = 0.1;

msg = ones(1, 48);
detector_array = ones(1, BUFF_SIZE);
out = zeros(1, BUFF_SIZE);
output = zeros(1, 240000);
%output = zeros(1, 600000);
gain = ones(1, 5000);
%gain = ones(1, 12500);
sum_output = 0;
gain_plot=zeros(1, 240000);

alpha = 1 /  (0.83333333333 * 48000.0);
setpoint = 42;
attack = 0.0001;
decay = 0.2;
count = 0;



% Set the sampling rate and duration of the signal
fs = 48000; % Hz
duration = 5; % seconds
%duration = 12.5; % seconds

% Set the time vector
t = 0:1/fs:duration-1/fs;

% Generate the sinusoid waveform
amplitude1 = 16384;
amplitude2 = 32768;
f = 100; % Hz
% x1 = [amplitude1*sin(2*pi*f*t(1:floor(length(t)/2))), ...
%    amplitude2*sin(2*pi*f*t(floor(length(t)/2)+1:end))];

% x1 = amplitude1*sin(2*pi*f*t(1:floor(length(t))));


x1 = [amplitude2*sin(2*pi*f*t(1:floor(length(t)/2))), ...
    amplitude1*sin(2*pi*f*t(floor(length(t)/2)+1:end))];

%   [x1,fs]=audioread("voice_samp_8k.wav\voice_samp_8k.wav");
%   x1 = 32768*interp(x1,6)';
%  x1=x1(1:389760);
% audiowrite("demoaudio.wav",x1,48000)
% soundsc(x1,48000)
% main loop
j=1;
k=1;
while j <  5000 %12500%
    % Red input from somewhere
     msg = x1(((j-1)*48)+1:(j)*48); 
    j = j + 1;
    detector = 0.0;
    
    % find max amplitude
    for i = 1:48
        if msg(i) > detector
            detector = msg(i);
        end
    end
    
    detector_array(count+1) = detector;
    count = count + 1;
    if count >= BUFF_SIZE
        count = 0;
    end
    
    % iir LPF
    out(1) = alpha * detector_array(1);
    for i = 2:BUFF_SIZE
        out(i) = (1 - alpha) * out(i-1) + alpha * detector_array(i);
    end
    
    % Average filter output
    for i = 1:BUFF_SIZE
        sum_output = sum_output + out(i);
    end
    
    sum_output = sum_output / BUFF_SIZE;
    
    % Compute Gain
    desiredGain = setpoint / sum_output;
    
    if desiredGain > 1
        gain(j) = (1 - attack) * desiredGain + attack * gain(j-1);
        % gain(j) = gain(j-1)+0.1;
    elseif desiredGain <= 1
        gain(j) = (1 - decay) * desiredGain + decay *  gain(j-1);
         % gain(j) = gain(j-1)-0.1;
    end
    
    % if sum_output < 0.01
    %     gain = 1;
    % end
    
    % Limit gain to allowable range
    if gain(j) > MAX_GAIN
        gain(j) = MAX_GAIN;
    elseif gain(j) < MIN_GAIN
        gain(j) = MIN_GAIN;
    end
    
    for i = 1:48
        output(k) = round(msg(i) * gain(j));
        k = 1 + k;
    end
    
    for i=((j-2)*48)+1:(j-1)*48
    gain_plot(i)=16384*gain(j);
    end
    
end


hold
plot(t,output,'LineWidth',1,'Color','b')
plot(t,x1,'LineWidth',1,'Color','r')
plot(t,gain_plot,'LineWidth',2,'Color','k')
hold off
axis([2.4 3 -75000 75000 ])
title('Attack Example')
xlabel('Seconds')
ylabel('Magnitude')
legend('Output Signal', 'Input Signal','Gain')
grid

