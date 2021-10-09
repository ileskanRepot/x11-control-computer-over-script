seconds=$(date +%s)
type=2      # EV_REL
code=0      # REL_X
value=100   # 100 pixels

printf '%08X%04X%04X%08X%08X\n' $value $code $type 0 $seconds  | xxd -r -p | perl -0777e 'print scalar reverse <>' > /dev/input/event15

type=0      # EV_SYN
code=0      # SYN_REPORT
value=0

printf '%08X%04X%04X%08X%08X\n' $value $code $type 0 $seconds  | xxd -r -p | perl -0777e 'print scalar reverse <>' > /dev/input/event15
