// Address: 0x14016f710
// Ghidra name: thunk_FUN_1401730d0
// ============ 0x14016f710 thunk_FUN_1401730d0 (size=5) ============


void thunk_FUN_1401730d0(void)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  longlong lVar4;

  undefined8 uStack_28;

  undefined8 uStack_20;

  undefined4 uStack_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  uStack_28 = 0;

  uStack_20 = 0;

  piVar3 = (int *)FUN_14016d780(0);

  if (piVar3 != (int *)0x0) {

    iVar2 = *piVar3;

    if (iVar2 != 0) {

      lVar4 = 0;

      do {

        cVar1 = FUN_14016d280(iVar2,&uStack_18);

        if (cVar1 != '\0') {

          if (lVar4 == 0) {

            uStack_28 = CONCAT44(uStack_14,uStack_18);

            uStack_20 = CONCAT44(uStack_c,uStack_10);

          }

          else {

            FUN_1401859f0(&uStack_28,&uStack_18,&uStack_28);

          }

        }

        iVar2 = piVar3[lVar4 + 1];

        lVar4 = lVar4 + 1;

      } while (iVar2 != 0);

    }

    FUN_1401841e0(piVar3);

  }

  lVar4 = DAT_1403fc410;

  *(undefined8 *)(DAT_1403fc410 + 0x338) = uStack_28;

  *(undefined8 *)(lVar4 + 0x340) = uStack_20;

  return;

}




