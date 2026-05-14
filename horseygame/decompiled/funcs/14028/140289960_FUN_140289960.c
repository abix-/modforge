// Address: 0x140289960
// Ghidra name: FUN_140289960
// ============ 0x140289960 FUN_140289960 (size=397) ============


longlong FUN_140289960(char param_1,longlong param_2,longlong param_3,undefined8 param_4,

                      undefined4 *param_5,int param_6,char param_7)



{

  undefined8 *puVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  int iVar5;

  longlong lVar6;

  longlong *plVar7;

  longlong *plVar8;

  longlong lVar9;

  int local_38;

  uint local_34;

  undefined4 local_30;

  

  if (param_2 != 0) {

    lVar6 = FUN_140289b60(param_4);

    if (lVar6 != 0) {

      iVar5 = FUN_140138fe0(lVar6 + 0x90);

      if (iVar5 == 0) {

        return lVar6;

      }

      puVar1 = *(undefined8 **)(lVar6 + 0x58);

      FUN_1401841e0(*puVar1);

      *puVar1 = 0;

    }

    plVar7 = (longlong *)FUN_1401841a0(1,0x18);

    if (plVar7 != (longlong *)0x0) {

      lVar6 = FUN_14012fc00(param_4);

      *plVar7 = lVar6;

      plVar8 = plVar7;

      if (lVar6 != 0) {

        uVar2 = param_5[1];

        uVar3 = param_5[2];

        uVar4 = param_5[3];

        *(undefined4 *)(plVar7 + 1) = *param_5;

        *(undefined4 *)((longlong)plVar7 + 0xc) = uVar2;

        *(undefined4 *)(plVar7 + 2) = uVar3;

        *(undefined4 *)((longlong)plVar7 + 0x14) = uVar4;

        local_34 = (uint)*(byte *)(param_3 + 2);

        local_30 = *(undefined4 *)(param_3 + 4);

        if (param_6 == 0) {

          param_6 = FUN_1401a92d0(param_3);

        }

        local_38 = param_6;

        lVar6 = FUN_14015d410(param_1,param_2,&local_38,plVar7);

        if ((param_1 != '\0') || (param_7 == '\0')) {

LAB_140289ad0:

          if (lVar6 == 0) {

            FUN_1401841e0(*plVar7);

            FUN_1401841e0(plVar7);

            return 0;

          }

          return lVar6;

        }

        plVar8 = (longlong *)FUN_1401841f0(0x18);

        if (plVar8 == (longlong *)0x0) {

          return 0;

        }

        lVar9 = FUN_14012fc00(param_4);

        *plVar8 = lVar9;

        if (lVar9 != 0) {

          uVar2 = param_5[1];

          uVar3 = param_5[2];

          uVar4 = param_5[3];

          *(undefined4 *)(plVar8 + 1) = *param_5;

          *(undefined4 *)((longlong)plVar8 + 0xc) = uVar2;

          *(undefined4 *)(plVar8 + 2) = uVar3;

          *(undefined4 *)((longlong)plVar8 + 0x14) = uVar4;

          lVar9 = FUN_14015d410(1,param_2,&local_38,plVar8);

          if (lVar9 == 0) {

            FUN_1401841e0(*plVar8);

            FUN_1401841e0(plVar8);

          }

          goto LAB_140289ad0;

        }

      }

      FUN_1401841e0(plVar8);

    }

  }

  return 0;

}




