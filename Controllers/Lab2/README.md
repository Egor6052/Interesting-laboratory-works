
For the program to output the obtained temperature:
Compilation:
```
g++ -o Start ./*.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
Start:
```
./Start
```

For the temperature reading and transmission program:

Compilation:
```
g++ -o start ./*.cpp
```
Old:
```
./Start
```


For emergency process termination and port release.
Use the lsof command to find which process is occupying port 8080:

```
lsof -i :8080
```
After obtaining the PID, you can kill the process using the kill command:
```
kill PID
```