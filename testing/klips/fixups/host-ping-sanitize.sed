s,\(64 bytes from .*: icmp_[rs]eq=. ttl=[0-9]*\) time=\([0-9]*.[0-9]*\) ms,\1 time=0.XXX ms,
s,\([0-9]* packets transmitted\, [0-9]* received\, [0-9]*% packet loss\, time \)\([0-9]*\)ms,\1XXXX,
s,\(+[0-9]* packets transmitted\, [0-9]* received\, +[0-9]* errors\, [0-9]*% packet loss\, time \)\([0-9]*\)ms,\1XXXX,
s,\(rtt min/avg/max/mdev = \).*\( ms\),\10.XXX/0.XXX/0.XXX/0.XXX\2,
s,\(TTL=[0-9]* ID=\)[0-9]* \(PROTO=ICMP TYPE=0 CODE=0 ID=\)[0-9]* \(SEQ=[0-9]*\),\1000 \2000 \3,

