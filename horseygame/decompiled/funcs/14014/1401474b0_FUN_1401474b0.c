// Address: 0x1401474b0
// Ghidra name: FUN_1401474b0
// ============ 0x1401474b0 FUN_1401474b0 (size=267) ============


void FUN_1401474b0(int param_1,int param_2,uint *param_3,int param_4,uint *param_5,int param_6)



{

  uint uVar1;

  uint *puVar2;

  uint *puVar3;

  int iVar4;

  uint uVar5;

  

  if (param_2 != 0) {

    do {

      param_2 = param_2 + -1;

      puVar2 = param_5;

      puVar3 = param_3;

      for (iVar4 = param_1; iVar4 != 0; iVar4 = iVar4 + -1) {

        uVar1 = *puVar3;

        puVar3 = puVar3 + 1;

        uVar5 = uVar1 >> 0x18;

        *puVar2 = ((((uVar1 >> 0x10 & 0xff) * uVar5) / 0xff | uVar5 << 8) << 8 |

                  ((uVar1 >> 8 & 0xff) * uVar5) / 0xff) << 8 | ((uVar1 & 0xff) * uVar5) / 0xff;

        puVar2 = puVar2 + 1;

      }

      param_3 = (uint *)((longlong)param_3 + (longlong)param_4);

      param_5 = (uint *)((longlong)param_5 + (longlong)param_6);

    } while (param_2 != 0);

  }

  return;

}




