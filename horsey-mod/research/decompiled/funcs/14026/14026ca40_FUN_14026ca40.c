// Address: 0x14026ca40
// Ghidra name: FUN_14026ca40
// ============ 0x14026ca40 FUN_14026ca40 (size=44) ============


char FUN_14026ca40(longlong param_1,char param_2)



{

  if (*(char *)(param_1 + 0x11) != '\0') {

    if (param_2 == '\0') {

      return '\x01';

    }

    if (param_2 == '\x01') {

      return '\0';

    }

    if (param_2 == '\x02') {

      return '\x03';

    }

    if (param_2 == '\x03') {

      return '\x02';

    }

  }

  return param_2;

}




