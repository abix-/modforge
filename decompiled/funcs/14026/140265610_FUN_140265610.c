// Address: 0x140265610
// Ghidra name: FUN_140265610
// ============ 0x140265610 FUN_140265610 (size=263) ============


ulonglong FUN_140265610(undefined8 *param_1,undefined8 param_2,char *param_3,int param_4)



{

  undefined2 uVar1;

  undefined2 uVar2;

  ulonglong in_RAX;

  ulonglong uVar3;

  undefined8 uVar4;

  

  if (0 < param_4) {

    if (*param_3 == '\x01') {

      if (param_4 < 0xe) {

        uVar3 = FUN_14012e080(7,"GIP: Discarding too-short firmware message");

        return uVar3 & 0xffffffffffffff00;

      }

      uVar1 = *(undefined2 *)(param_3 + 6);

      uVar2 = *(undefined2 *)(param_3 + 8);

      FUN_14012e080(7,"GIP: Firmware version: %d.%d.%d rev %d",uVar1,uVar2,

                    *(undefined2 *)(param_3 + 10),*(undefined2 *)(param_3 + 0xc));

      *(undefined2 *)((longlong)param_1 + 0x34) = uVar1;

      *(undefined2 *)((longlong)param_1 + 0x36) = uVar2;

      uVar4 = 0x45e;

      if ((*(short *)(*(longlong *)*param_1 + 0x20) == 0x45e) &&

         (uVar4 = 0xb00, *(short *)(*(longlong *)*param_1 + 0x22) == 0xb00)) {

        uVar3 = FUN_1402651d0(param_1);

        return uVar3;

      }

      return CONCAT71((int7)((ulonglong)uVar4 >> 8),1);

    }

    in_RAX = FUN_14012e080(7,"GIP: Unimplemented Firmware message");

  }

  return in_RAX & 0xffffffffffffff00;

}




