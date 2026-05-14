// Address: 0x140272890
// Ghidra name: FUN_140272890
// ============ 0x140272890 FUN_140272890 (size=119) ============


undefined1 FUN_140272890(longlong param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  undefined1 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  FUN_140274450(lVar1);

  if (*(char *)(lVar1 + 0x12) == '\0') {

LAB_1402728c3:

    if (*(char *)(lVar1 + 0x19) == '\0') {

      uVar2 = FUN_14012e850("That operation is not supported");

      return uVar2;

    }

    if (param_3 == '\0') goto LAB_1402728f1;

  }

  else {

    if (param_3 == '\0') goto LAB_1402728f1;

    if (*(char *)(lVar1 + 0x21) == '\0') goto LAB_1402728c3;

  }

  FUN_140273ce0(param_1);

LAB_1402728f1:

  *(char *)(lVar1 + 0x23) = param_3;

  return 1;

}




