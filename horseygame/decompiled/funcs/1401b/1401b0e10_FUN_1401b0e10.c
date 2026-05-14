// Address: 0x1401b0e10
// Ghidra name: FUN_1401b0e10
// ============ 0x1401b0e10 FUN_1401b0e10 (size=978) ============


void FUN_1401b0e10(longlong param_1)



{

  undefined8 *puVar1;

  int iVar2;

  longlong lVar3;

  ulonglong uVar4;

  longlong lVar5;

  longlong lVar6;

  uint uVar7;

  longlong lVar8;

  int iVar9;

  ulonglong uVar10;

  

  puVar1 = *(undefined8 **)(param_1 + 0x298);

  FUN_1401c0880(puVar1);

  lVar3 = (longlong)(*(int *)(puVar1 + 0xf7) + -1);

  if (-1 < *(int *)(puVar1 + 0xf7) + -1) {

    do {

      FUN_1401bf8b0(*(undefined8 *)(param_1 + 0x298),**(undefined8 **)(puVar1[0xf6] + lVar3 * 8));

      lVar3 = lVar3 + -1;

    } while (-1 < lVar3);

  }

  FUN_1401841e0(puVar1[0xf6]);

  FUN_1401c0880(*(undefined8 *)(param_1 + 0x298));

  FUN_1401841e0(puVar1[0xfa]);

  uVar10 = 0;

  uVar4 = uVar10;

  if (*(int *)(puVar1 + 0x106) != 0) {

    do {

      FUN_1401b8f50(puVar1,**(undefined8 **)(uVar4 * 8 + puVar1[0x105]));

      FUN_1401841e0(*(undefined8 *)(puVar1[0x105] + uVar4 * 8));

      uVar7 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar7;

    } while (uVar7 < *(uint *)(puVar1 + 0x106));

  }

  FUN_1401841e0(puVar1[0x105]);

  uVar4 = uVar10;

  if (*(int *)(puVar1 + 0x108) != 0) {

    do {

      FUN_1401b9150(puVar1,*(undefined8 *)(puVar1[0x107] + uVar4 * 8));

      uVar7 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar7;

    } while (uVar7 < *(uint *)(puVar1 + 0x108));

  }

  FUN_1401841e0(puVar1[0x107]);

  uVar4 = uVar10;

  if (*(int *)(puVar1 + 0xfe) != 0) {

    do {

      (*(code *)puVar1[0x173])(puVar1[0xae],**(undefined8 **)(uVar4 * 8 + puVar1[0xfd]),0);

      FUN_1401841e0(*(undefined8 *)(uVar4 * 8 + puVar1[0xfd]));

      uVar7 = (int)uVar4 + 1;

      uVar4 = (ulonglong)uVar7;

    } while (uVar7 < *(uint *)(puVar1 + 0xfe));

  }

  FUN_1401841e0(puVar1[0xfd]);

  FUN_140179b30(puVar1[0xfc]);

  FUN_1401aafa0(puVar1[0xff]);

  FUN_1401aafa0(puVar1[0x100]);

  FUN_1401aafa0(puVar1[0x101]);

  FUN_1401aafa0(puVar1[0x102]);

  FUN_1401aafa0(puVar1[0x103]);

  FUN_1401aafa0(puVar1[0x104]);

  lVar3 = 0x20;

  do {

    lVar6 = puVar1[0xb3] + uVar10;

    iVar9 = *(int *)(lVar6 + 0x10) + -1;

    if (-1 < iVar9) {

      lVar8 = (longlong)iVar9 * 8;

      do {

        iVar2 = *(int *)(*(longlong *)(*(longlong *)(lVar6 + 8) + lVar8) + 0x20) + -1;

        lVar5 = (longlong)iVar2;

        if (-1 < iVar2) {

          do {

            FUN_1401bcc70(puVar1,*(undefined8 *)

                                  (*(longlong *)

                                    (*(longlong *)(*(longlong *)(lVar6 + 8) + lVar8) + 0x18) +

                                  lVar5 * 8));

            lVar5 = lVar5 + -1;

          } while (-1 < lVar5);

        }

        FUN_1401b8810(puVar1,lVar6,iVar9);

        lVar8 = lVar8 + -8;

        iVar9 = iVar9 + -1;

      } while (-1 < iVar9);

    }

    FUN_1401841e0(*(undefined8 *)(uVar10 + 8 + puVar1[0xb3]));

    FUN_1401841e0(*(undefined8 *)(uVar10 + 0x18 + puVar1[0xb3]));

    uVar10 = uVar10 + 0x28;

    lVar3 = lVar3 + -1;

  } while (lVar3 != 0);

  FUN_1401841e0(puVar1[0xb3]);

  FUN_1401841e0(puVar1[0x10a]);

  FUN_1401841e0(puVar1[0x10c]);

  FUN_1401841e0(puVar1[0x110]);

  FUN_1401841e0(puVar1[0x112]);

  FUN_1401841e0(puVar1[0x114]);

  FUN_1401841e0(puVar1[0x10e]);

  FUN_1401841e0(puVar1[0x116]);

  FUN_1401841e0(puVar1[0x125]);

  FUN_140179b30(puVar1[0x118]);

  FUN_140179b30(puVar1[0x119]);

  FUN_140179b30(puVar1[0x11a]);

  FUN_140179b30(puVar1[0x11b]);

  FUN_140179b30(puVar1[0x11c]);

  FUN_140179b30(puVar1[0x11d]);

  FUN_140179b30(puVar1[0x11e]);

  FUN_140179b30(puVar1[0x11f]);

  FUN_140179b30(puVar1[0x120]);

  FUN_140179b30(puVar1[0x121]);

  FUN_140179b30(puVar1[0x122]);

  (*(code *)puVar1[0x172])(puVar1[0xae],0);

  (*(code *)puVar1[0x129])(*puVar1,0);

  FUN_1401747e0(*(undefined4 *)(puVar1 + 0xb0));

  FUN_1401841e0(puVar1);

  FUN_1401841e0(param_1);

  FUN_1401741d0();

  return;

}




