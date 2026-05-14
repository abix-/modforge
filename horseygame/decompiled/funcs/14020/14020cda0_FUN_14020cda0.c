// Address: 0x14020cda0
// Ghidra name: FUN_14020cda0
// ============ 0x14020cda0 FUN_14020cda0 (size=133) ============


undefined8 FUN_14020cda0(longlong param_1,int param_2,undefined2 param_3)



{

  longlong lVar1;

  longlong lVar2;

  undefined8 uVar3;

  char *pcVar4;

  

  _guard_check_icall();

  if ((param_1 == 0) || (lVar1 = *(longlong *)(param_1 + 0x148), lVar1 == 0)) {

    pcVar4 = "Invalid joystick";

  }

  else {

    if ((-1 < param_2) && (param_2 < (int)(uint)*(ushort *)(lVar1 + 0x34))) {

      lVar2 = *(longlong *)(lVar1 + 0xb8);

      *(undefined2 *)(lVar2 + (longlong)param_2 * 2) = param_3;

      *(uint *)(lVar1 + 0xb0) = *(uint *)(lVar1 + 0xb0) | 1;

      return CONCAT71((int7)((ulonglong)lVar2 >> 8),1);

    }

    pcVar4 = "Invalid axis index";

  }

  uVar3 = FUN_14012e850(pcVar4);

  return uVar3;

}




