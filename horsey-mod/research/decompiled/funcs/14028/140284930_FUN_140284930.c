// Address: 0x140284930
// Ghidra name: FUN_140284930
// ============ 0x140284930 FUN_140284930 (size=336) ============


undefined8 FUN_140284930(longlong param_1,longlong param_2)



{

  char cVar1;

  size_t sVar2;

  longlong lVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  int iVar8;

  

  lVar7 = 0;

  lVar6 = 0;

  _guard_check_icall();

  iVar8 = 0;

  if (0 < *(int *)(param_1 + 0xa8)) {

    lVar4 = 0;

    do {

      lVar3 = *(longlong *)(*(longlong *)(param_1 + 0xb0) + lVar4 * 8);

      cVar1 = (**(code **)(*(longlong *)(lVar3 + 0x68) + 0x50))(lVar3,param_2);

      if (cVar1 == '\0') {

        *(undefined1 *)(lVar3 + 0x9a) = 1;

        while (0 < lVar4) {

          lVar4 = lVar4 + -1;

          lVar6 = *(longlong *)(*(longlong *)(param_1 + 0xb0) + lVar4 * 8);

          (**(code **)(*(longlong *)(lVar6 + 0x68) + 0x88))(lVar6,param_2);

        }

        FUN_1401841e0(lVar7);

        return 0;

      }

      if (*(char **)(param_2 + 0x18) != (char *)0x0) {

        sVar2 = strlen(*(char **)(param_2 + 0x18));

        lVar5 = sVar2 + 1 + lVar6;

        lVar3 = FUN_140184230(lVar7,lVar5);

        if (lVar3 != 0) {

          lVar6 = lVar5;

          if (lVar7 == 0) {

            FUN_14012f1a0(lVar3,*(undefined8 *)(param_2 + 0x18),lVar5);

            lVar7 = lVar3;

          }

          else {

            FUN_14012f120(lVar3,&DAT_140331a5c);

            FUN_14012f120(lVar3,*(undefined8 *)(param_2 + 0x18),lVar5);

            lVar7 = lVar3;

          }

        }

        FUN_1401841e0(*(undefined8 *)(param_2 + 0x18));

        *(undefined8 *)(param_2 + 0x18) = 0;

      }

      iVar8 = iVar8 + 1;

      lVar4 = lVar4 + 1;

    } while (iVar8 < *(int *)(param_1 + 0xa8));

  }

  FUN_1401841e0(*(undefined8 *)(param_2 + 0x18));

  *(longlong *)(param_2 + 0x18) = lVar7;

  return 1;

}




