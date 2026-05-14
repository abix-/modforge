// Address: 0x1402e9630
// Ghidra name: FUN_1402e9630
// ============ 0x1402e9630 FUN_1402e9630 (size=233) ============


longlong * FUN_1402e9630(longlong *param_1)



{

  longlong *plVar1;

  uint uVar2;

  uint uVar3;

  longlong lVar4;

  longlong *plVar5;

  bool bVar6;

  

  plVar5 = (longlong *)(DAT_1403fed30 + 0x18);

  plVar1 = plVar5 + (longlong)DAT_1403fed28 + -3;

  do {

    if (plVar5 == plVar1) {

LAB_1402e96ac:

      *param_1 = 0;

      return param_1;

    }

    lVar4 = *plVar5;

    if (lVar4 == 0) {

      lVar4 = _calloc_base(1);

      *plVar5 = lVar4;

      FUN_1402e9a80(0);

      if (*plVar5 != 0) {

        *(undefined4 *)(*plVar5 + 0x18) = 0xffffffff;

        InitializeCriticalSectionEx((LPCRITICAL_SECTION)(*plVar5 + 0x30),4000,0);

        lVar4 = *plVar5;

        LOCK();

        *(uint *)(lVar4 + 0x14) = *(uint *)(lVar4 + 0x14) | 0x2000;

        UNLOCK();

        FUN_1402e1710(lVar4);

LAB_1402e96c8:

        *param_1 = lVar4;

        return param_1;

      }

      goto LAB_1402e96ac;

    }

    if ((*(uint *)(lVar4 + 0x14) >> 0xd & 1) == 0) {

      FUN_1402e1710(lVar4);

      uVar3 = *(uint *)(lVar4 + 0x14);

      do {

        LOCK();

        uVar2 = *(uint *)(lVar4 + 0x14);

        bVar6 = uVar3 == uVar2;

        if (bVar6) {

          *(uint *)(lVar4 + 0x14) = uVar3 | 0x2000;

          uVar2 = uVar3;

        }

        uVar3 = uVar2;

        UNLOCK();

      } while (!bVar6);

      if ((~(byte)(uVar3 >> 0xd) & 1) != 0) goto LAB_1402e96c8;

      FUN_1402e171c(lVar4);

    }

    plVar5 = plVar5 + 1;

  } while( true );

}




