// Address: 0x140270650
// Ghidra name: FUN_140270650
// ============ 0x140270650 FUN_140270650 (size=119) ============


undefined1 FUN_140270650(longlong param_1,undefined8 param_2,char param_3)



{

  longlong lVar1;

  undefined1 uVar2;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  FUN_140271e10(lVar1);

  if (*(char *)(lVar1 + 0x13) == '\0') {

LAB_140270683:

    if (*(char *)(lVar1 + 0x19) == '\0') {

      uVar2 = FUN_14012e850("That operation is not supported");

      return uVar2;

    }

    if (param_3 == '\0') goto LAB_1402706b1;

  }

  else {

    if (param_3 == '\0') goto LAB_1402706b1;

    if (*(char *)(lVar1 + 0x21) == '\0') goto LAB_140270683;

  }

  FUN_140271460(param_1);

LAB_1402706b1:

  *(char *)(lVar1 + 0x24) = param_3;

  return 1;

}




