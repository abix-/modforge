// Address: 0x140287230
// Ghidra name: FUN_140287230
// ============ 0x140287230 FUN_140287230 (size=474) ============


void FUN_140287230(longlong param_1)



{

  int iVar1;

  longlong *plVar2;

  undefined1 uVar3;

  int iVar4;

  undefined8 uVar5;

  longlong lVar6;

  ushort uVar7;

  longlong lVar8;

  undefined4 auStack_178 [14];

  undefined8 uStack_140;

  ushort local_118 [2];

  ushort local_114;

  ushort local_110;

  ushort local_10c;

  ushort local_108;

  ushort local_104;

  ushort local_100;

  ushort local_fc;

  char acStack_e8 [224];

  

  uStack_140 = 0x140287245;

  uVar5 = FUN_140149300();

  plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

  uStack_140 = 0x140287267;

  iVar4 = (**(code **)(*plVar2 + 0x48))(plVar2,0x110,local_118);

  if ((iVar4 == -0x7ff8ffe2) || (iVar4 == -0x7ff8fff4)) {

    uStack_140 = 0x14028728a;

    (**(code **)(**(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10) + 0x38))();

    plVar2 = *(longlong **)(*(longlong *)(param_1 + 0x148) + 0x10);

    uStack_140 = 0x1402872a9;

    iVar4 = (**(code **)(*plVar2 + 0x48))(plVar2,0x110,local_118);

  }

  if (iVar4 == 0) {

    lVar8 = *(longlong *)(param_1 + 0x148);

    iVar4 = 0;

    if (0 < *(int *)(lVar8 + 0xc48)) {

      lVar6 = 0x48;

      do {

        iVar1 = *(int *)(lVar6 + 4 + lVar8);

        if (iVar1 == 0) {

          uStack_140 = 0x1402873c7;

          FUN_14015ad00(uVar5,param_1,*(undefined1 *)(lVar6 + 8 + lVar8),

                        acStack_e8[*(int *)(lVar6 + lVar8) - 0x30] != '\0');

        }

        else if (iVar1 == 1) {

          switch(*(undefined4 *)(lVar6 + lVar8)) {

          case 0:

            uVar7 = local_118[0];

            break;

          default:

            goto switchD_140287353_caseD_1;

          case 4:

            uVar7 = local_114;

            break;

          case 8:

            uVar7 = local_110;

            break;

          case 0xc:

            uVar7 = local_10c;

            break;

          case 0x10:

            uVar7 = local_108;

            break;

          case 0x14:

            uVar7 = local_104;

            break;

          case 0x18:

            uVar7 = local_100;

            break;

          case 0x1c:

            uVar7 = local_fc;

          }

          uStack_140 = 0x1402873a4;

          FUN_14015aab0(uVar5,param_1,*(undefined1 *)(lVar6 + 8 + lVar8),uVar7);

        }

        else if (iVar1 == 2) {

          uStack_140 = 0x140287318;

          uVar3 = FUN_140286ff0(auStack_178[*(uint *)(lVar6 + lVar8)]);

          uStack_140 = 0x14028732d;

          FUN_14015ae90(uVar5,param_1,*(undefined1 *)(lVar6 + 8 + lVar8),uVar3);

        }

switchD_140287353_caseD_1:

        lVar8 = *(longlong *)(param_1 + 0x148);

        iVar4 = iVar4 + 1;

        lVar6 = lVar6 + 0xc;

      } while (iVar4 < *(int *)(lVar8 + 0xc48));

    }

  }

  return;

}




