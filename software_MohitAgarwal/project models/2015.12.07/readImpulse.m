f = SimulinkRealTime.fileSystem;

h = fopen(f, 'impulse1.dat');
data = fread(f,h);
f.fclose(h);

x=SimulinkRealTime.utils.getFileScopeData(data);
figure,
plot(x.data(:,2),x.data(:,1),'r'), 