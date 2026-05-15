// Address: 0x140160cb0
// Ghidra name: FUN_140160cb0
// ============ 0x140160cb0 FUN_140160cb0 (size=247) ============


undefined8

FUN_140160cb0(char *param_1,char *param_2,int param_3,int param_4,undefined4 param_5,

             undefined4 param_6)



{

  uint uVar1;

  longlong lVar2;

  undefined8 uVar3;

  uint uVar4;

  uint *puVar5;

  char cVar6;

  uint uVar7;

  char cVar8;

  int iVar9;

  

  uVar7 = param_3 + 7U & 0xfffffff8;

  cVar6 = '\0';

  cVar8 = '\0';

  lVar2 = FUN_140145e60(uVar7,param_4);

  uVar3 = 0;

  if (lVar2 != 0) {

    iVar9 = 0;

    if (0 < param_4) {

      do {

        uVar4 = 0;

        puVar5 = (uint *)((longlong)(iVar9 * *(int *)(lVar2 + 0x10)) + *(longlong *)(lVar2 + 0x18));

        if (0 < (int)uVar7) {

          do {

            if ((uVar4 & 7) == 0) {

              cVar6 = *param_1;

              param_1 = param_1 + 1;

              cVar8 = *param_2;

              param_2 = param_2 + 1;

            }

            if (cVar8 < '\0') {

              uVar1 = ((int)cVar6 >> 0x1f & 0xff000001U) - 1;

            }

            else {

              uVar1 = (int)cVar6 >> 0x1f & 0xffffff;

            }

            *puVar5 = uVar1;

            cVar6 = cVar6 * '\x02';

            puVar5 = puVar5 + 1;

            cVar8 = cVar8 * '\x02';

            uVar4 = uVar4 + 1;

          } while ((int)uVar4 < (int)uVar7);

        }

        iVar9 = iVar9 + 1;

      } while (iVar9 < param_4);

    }

    uVar3 = FUN_140160aa0(lVar2,param_5,param_6);

    FUN_140146010(lVar2);

  }

  return uVar3;

}




