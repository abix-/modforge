// Address: 0x1401b3470
// Ghidra name: FUN_1401b3470
// ============ 0x1401b3470 FUN_1401b3470 (size=482) ============


undefined8

FUN_1401b3470(longlong param_1,uint param_2,longlong param_3,char param_4,undefined8 *param_5)



{

  longlong lVar1;

  int iVar2;

  longlong *plVar3;

  longlong lVar4;

  undefined8 uVar5;

  undefined4 local_38 [2];

  undefined8 local_30;

  longlong local_28;

  uint local_20;

  

  local_38[0] = 5;

  lVar1 = *(longlong *)(param_1 + 0x598) + (ulonglong)param_2 * 0x28;

  local_28 = param_3;

  local_20 = param_2;

  plVar3 = (longlong *)FUN_1401841f0(0x68);

  plVar3[2] = param_3;

  plVar3[8] = 0;

  plVar3[9] = 0;

  lVar4 = FUN_140179a30();

  plVar3[0xb] = lVar4;

  *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;

  lVar4 = FUN_140184230(*(undefined8 *)(lVar1 + 8),(ulonglong)*(uint *)(lVar1 + 0x10) << 3);

  *(longlong *)(lVar1 + 8) = lVar4;

  *(longlong **)(lVar4 + (ulonglong)(*(int *)(lVar1 + 0x10) - 1) * 8) = plVar3;

  local_30 = 0;

  *(undefined1 *)(plVar3 + 7) = 1;

  lVar4 = FUN_1401841f0(8);

  plVar3[3] = lVar4;

  *(undefined4 *)(plVar3 + 4) = 0;

  *(undefined4 *)((longlong)plVar3 + 0x24) = 1;

  lVar4 = FUN_1401841f0(8);

  plVar3[5] = lVar4;

  *(undefined4 *)(plVar3 + 6) = 0;

  *(undefined4 *)((longlong)plVar3 + 0x34) = 1;

  FUN_140139010(plVar3 + 0xc,0);

  *plVar3 = lVar1;

  iVar2 = (**(code **)(param_1 + 0x9f8))(*(undefined8 *)(param_1 + 0x570),local_38,0,plVar3 + 1);

  if (iVar2 == 0) {

    if (param_4 == '\0') {

      plVar3[10] = 0;

    }

    else {

      iVar2 = (**(code **)(param_1 + 0xc38))

                        (*(undefined8 *)(param_1 + 0x570),plVar3[1],0,0xffffffffffffffff,0,

                         plVar3 + 10);

      if (iVar2 != 0) {

        if (*(char *)(param_1 + 0x57c) == '\0') {

          uVar5 = FUN_1401c0ba0(iVar2);

          FUN_14012e850("%s %s","vkMapMemory",uVar5);

          return 0;

        }

        uVar5 = FUN_1401c0ba0(iVar2);

                    /* WARNING: Subroutine does not return */

        FUN_14012e0b0(9,"%s %s","vkMapMemory",uVar5);

      }

    }

    FUN_1401bb850(param_1,plVar3,0,plVar3[2]);

    *param_5 = plVar3;

    uVar5 = 1;

  }

  else {

    FUN_1401841e0(plVar3[5]);

    *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + -1;

    uVar5 = FUN_140184230(*(undefined8 *)(lVar1 + 8),(ulonglong)*(uint *)(lVar1 + 0x10) << 3);

    *(undefined8 *)(lVar1 + 8) = uVar5;

    FUN_1401841e0(plVar3);

    uVar5 = 0;

  }

  return uVar5;

}




