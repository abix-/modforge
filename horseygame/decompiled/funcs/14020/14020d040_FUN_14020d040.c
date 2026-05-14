// Address: 0x14020d040
// Ghidra name: FUN_14020d040
// ============ 0x14020d040 FUN_14020d040 (size=208) ============


undefined8

FUN_14020d040(longlong param_1,int param_2,int param_3,undefined1 param_4,undefined4 param_5,

             undefined4 param_6,undefined4 param_7)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  char *pcVar4;

  longlong lVar5;

  

  lVar5 = (longlong)param_3;

  _guard_check_icall();

  if ((param_1 == 0) || (lVar1 = *(longlong *)(param_1 + 0x148), lVar1 == 0)) {

    pcVar4 = "Invalid joystick";

  }

  else if ((param_2 < 0) || ((int)(uint)*(ushort *)(lVar1 + 0x3c) <= param_2)) {

    pcVar4 = "Invalid touchpad index";

  }

  else {

    if ((-1 < param_3) &&

       (param_3 < *(int *)(*(longlong *)(lVar1 + 0xd8) + (longlong)param_2 * 0x10))) {

      lVar2 = *(longlong *)(*(longlong *)(lVar1 + 0xd8) + 8 + (longlong)param_2 * 0x10);

      *(undefined4 *)(lVar2 + 4 + lVar5 * 0x10) = param_5;

      *(undefined4 *)(lVar2 + 0xc + lVar5 * 0x10) = param_7;

      *(undefined4 *)(lVar2 + 8 + lVar5 * 0x10) = param_6;

      *(undefined1 *)(lVar2 + lVar5 * 0x10) = param_4;

      *(uint *)(lVar1 + 0xb0) = *(uint *)(lVar1 + 0xb0) | 0x10;

      return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

    }

    pcVar4 = "Invalid finger index";

  }

  uVar3 = FUN_14012e850(pcVar4);

  return uVar3;

}




