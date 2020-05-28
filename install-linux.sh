echo Compiling program...
g++ *.cpp *.h *.hpp -o jason
echo Adding to PATH...
export PATH=$PATH:$(pwd)
chmod +x jason
echo Restarting profile
. ~/.profile