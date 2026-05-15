// Address: 0x1402f5710
// Ghidra name: FUN_1402f5710
// ============ 0x1402f5710 FUN_1402f5710 (size=88) ============


int FUN_1402f5710(ushort *param_1,ushort *param_2,longlong param_3)



{

  ushort uVar1;

  ushort uVar2;

  uint uVar3;

  uint uVar4;

  

  if (param_3 != 0) {

    do {

      uVar1 = *param_1;

      uVar3 = (uint)uVar1;

      param_1 = param_1 + 1;

      uVar2 = *param_2;

      param_2 = param_2 + 1;

      uVar4 = (uint)uVar2;

      if ((uint)uVar1 != (uint)uVar2) {

        uVar3 = uVar1 + 0x20;

        if (0x19 < uVar1 - 0x41) {

          uVar3 = (uint)uVar1;

        }

        uVar4 = uVar2 + 0x20;

        if (0x19 < uVar2 - 0x41) {

          uVar4 = (uint)uVar2;

        }

      }

    } while (((uVar3 - uVar4 == 0) && (uVar3 != 0)) && (param_3 = param_3 + -1, param_3 != 0));

    return uVar3 - uVar4;

  }

  return 0;

}




