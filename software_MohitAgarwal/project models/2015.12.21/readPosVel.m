f = SimulinkRealTime.fileSystem;

h = fopen(f, 'pos_vel.dat');
data = fread(f,h);
f.fclose(h);

x=SimulinkRealTime.utils.getFileScopeData(data);
figure,
plot(x.data(:,3),x.data(:,1),'r'), hold on, plot(x.data(:,3),x.data(:,2),'b')
