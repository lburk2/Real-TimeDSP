BUFF_SIZE = 200;
MAX_GAIN = 4;
MIN_GAIN = 0.1;

msg = zeros(1, 48);
detector_array = zeros(1, BUFF_SIZE);
out = zeros(1, BUFF_SIZE);
output = zeros(1, 240000);
gain = ones(1, 5000);
sum_output = 0;

alpha = 1 /  (0.83333333333 * 48000.0);
setpoint = 41;
attack = 0.0000001;
decay = 0.99999;

count = 0;


% Set the sampling rate and duration of the signal
fs = 48000; % Hz
duration = 5; % seconds

% Set the time vector
t = 0:1/fs:duration-1/fs;

% Generate the sinusoid waveform
amplitude1 = 16384;
amplitude2 = 32768;
f = 100; % Hz
x1 = [amplitude1*sin(2*pi*f*t(1:floor(length(t)/2))), ...
    amplitude2*sin(2*pi*f*t(floor(length(t)/2)+1:end))];

% x1 = amplitude1*sin(2*pi*f*t(1:floor(length(t))));

% 
% x1 = [amplitude2*sin(2*pi*f*t(1:floor(length(t)/2))), ...
%     amplitude1*sin(2*pi*f*t(floor(length(t)/2)+1:end))];

% main loop
j=0;
k=1;
while j < 5000
    % Red input from somewhere
     msg = x1((j*48)+1:(j+1)*48); 
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
        gain(j) = (1 - attack) * desiredGain + attack * gain(j);
    elseif desiredGain <= 1
        gain(j) = (1 - decay) * desiredGain + decay * gain(j);
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
end
