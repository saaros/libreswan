: ==== start ====
TESTNAME=ikev2-09-rw-rsa
source /testing/pluto/bin/eastnlocal.sh

ipsec setup start
/testing/pluto/bin/wait-until-pluto-started

ipsec whack --whackrecord /var/tmp/ikev2.record
ipsec auto --add  westnet-eastnet-ikev2
echo "initdone"
