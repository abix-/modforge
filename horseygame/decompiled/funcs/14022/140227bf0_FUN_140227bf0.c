// Address: 0x140227bf0
// Ghidra name: FUN_140227bf0
// ============ 0x140227bf0 FUN_140227bf0 (size=195) ============


longlong FUN_140227bf0(longlong param_1,uint param_2,undefined4 param_3,undefined4 param_4)



{

  longlong *plVar1;

  longlong lVar2;

  longlong lVar3;

  undefined4 *puVar4;

  ulonglong uVar5;

  

  uVar5 = (ulonglong)param_2;

  lVar2 = FUN_1401841a0(1,0x18);

  if (lVar2 != 0) {

    lVar3 = FUN_1401841a0(1,((longlong)(int)param_2 + 2) * 0x10);

    if (lVar3 != 0) {

      *(undefined4 *)(lVar3 + 0x10) = param_3;

      *(undefined4 *)(lVar3 + 0x14) = param_4;

      *(uint *)(lVar3 + 0x18) = param_2;

      if (0 < (int)param_2) {

        puVar4 = (undefined4 *)(param_1 + 8);

        do {

          *(undefined8 *)((lVar3 - param_1) + 0x18 + (longlong)puVar4) =

               *(undefined8 *)(puVar4 + -2);

          *(undefined4 *)((lVar3 - param_1) + 0x20 + (longlong)puVar4) = *puVar4;

          plVar1 = (longlong *)(puVar4 + -2);

          puVar4 = puVar4 + 4;

          *(int *)(*plVar1 + 0x20) = *(int *)(*plVar1 + 0x20) + 1;

          uVar5 = uVar5 - 1;

        } while (uVar5 != 0);

      }

      *(longlong *)(lVar2 + 8) = lVar3;

      return lVar2;

    }

    FUN_1401841e0(lVar2);

  }

  return 0;

}




