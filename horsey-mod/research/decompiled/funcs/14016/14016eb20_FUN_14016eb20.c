// Address: 0x14016eb20
// Ghidra name: FUN_14016eb20
// ============ 0x14016eb20 FUN_14016eb20 (size=187) ============


undefined8 FUN_14016eb20(undefined4 param_1,undefined8 *param_2)



{

  undefined8 uVar1;

  char cVar2;

  longlong in_RCX;

  

  if (param_2 != (undefined8 *)0x0) {

    param_1 = 0;

    *param_2 = 0;

    param_2[1] = 0;

  }

  if (DAT_1403fc410 == 0) {

    FUN_1401730c0();

    return 0;

  }

  if (in_RCX != 0) {

    if (DAT_1403e3d60 != '\0') {

      cVar2 = FUN_1401aa7c0(param_1,1);

      if (cVar2 == '\0') goto LAB_14016ebc2;

    }

    if (param_2 != (undefined8 *)0x0) {

      if ((((undefined8 *)(in_RCX + 0x124) != (undefined8 *)0x0) && (0 < *(int *)(in_RCX + 300))) &&

         (0 < *(int *)(in_RCX + 0x130))) {

        uVar1 = *(undefined8 *)(in_RCX + 300);

        *param_2 = *(undefined8 *)(in_RCX + 0x124);

        param_2[1] = uVar1;

        return 1;

      }

      *(undefined4 *)(param_2 + 1) = *(undefined4 *)(in_RCX + 0x20);

      *(undefined4 *)((longlong)param_2 + 0xc) = *(undefined4 *)(in_RCX + 0x24);

    }

    return 1;

  }

LAB_14016ebc2:

  FUN_14012e850("Invalid window");

  return 0;

}




