echo flag > flag
sudo chown root:root flag
sudo chmod 700 flag

mkdir hax
ln -s "$(pwd)"/flag hax/flag
touch hax/asd

gcc readflag.c -o readflag   
sudo chown root:root ./readflag
sudo chmod u+s ./readflag
         
gcc racing.c -o racing 

./racing hax/flag hax/asd
./readflag hax/flag
