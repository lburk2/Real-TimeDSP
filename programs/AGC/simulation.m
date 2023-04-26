t=0:2*pi/2304:2*pi;

x=sin(t);

x=round(x*32767);

x=x(1:end-1)';

detector_array=zeros(48,1);
detector=0;
%take 48 samples and get power

for k=0:47
    for i=(k*48):(k*48+48)
        detector=detector+x(i+1)^2;
    end
    detector_array(k+1)=detector/48;
end

B=1/10*ones(10,1);
out=filter(B,1,detector_array);

compare=mean(out);


   
