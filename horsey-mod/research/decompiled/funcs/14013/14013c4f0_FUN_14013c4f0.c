// Address: 0x14013c4f0
// Ghidra name: FUN_14013c4f0
// ============ 0x14013c4f0 FUN_14013c4f0 (size=196) ============


void FUN_14013c4f0(undefined8 param_1,longlong param_2,int param_3,byte param_4)



{

  byte bVar1;

  longlong lVar2;

  int iVar3;

  int *piVar4;

  

  _guard_check_icall();

  lVar2 = *(longlong *)(param_2 + 0x40);

  iVar3 = 0;

  bVar1 = *(byte *)(lVar2 + param_3);

  if (0 < *(int *)(param_2 + 0x28)) {

    lVar2 = 0;

    do {

      piVar4 = (int *)(*(longlong *)(param_2 + 0x30) + lVar2);

      if (((*piVar4 == 3) && (param_3 == piVar4[1])) &&

         ((byte)((byte)piVar4[2] & (param_4 ^ bVar1)) != 0)) {

        if (((byte)piVar4[2] & param_4) == 0) {

          FUN_14013c910(param_1,param_2);

        }

        else if (piVar4[4] == 2) {

          FUN_140141cf0(param_1,param_2,piVar4[5],(short)piVar4[7]);

        }

        else {

          FUN_140141d70(param_1,param_2,piVar4[5],1);

        }

      }

      iVar3 = iVar3 + 1;

      lVar2 = lVar2 + 0x20;

    } while (iVar3 < *(int *)(param_2 + 0x28));

    lVar2 = *(longlong *)(param_2 + 0x40);

  }

  *(byte *)(lVar2 + param_3) = param_4;

  return;

}




