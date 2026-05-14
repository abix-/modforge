// Address: 0x140005a10
// Ghidra name: FUN_140005a10
// ============ 0x140005a10 FUN_140005a10 (size=725) ============


undefined8 * FUN_140005a10(undefined8 *param_1,undefined8 *param_2,undefined1 param_3)



{

  undefined8 uVar1;

  ulonglong uVar2;

  uint uVar3;

  ulonglong uVar4;

  int iVar5;

  char cVar6;

  int iVar7;

  longlong lVar8;

  bool bVar9;

  

  *(undefined4 *)((longlong)param_1 + 0xc) = 0x80;

  uVar2 = 0;

  *(undefined4 *)(param_1 + 1) = 0;

  uVar1 = _malloc_base(0x800);

  *param_1 = uVar1;

  FUN_1402f94c0(uVar1,0,(longlong)*(int *)((longlong)param_1 + 0xc) << 4);

  bVar9 = DAT_1403ff7b5 == '\0';

  param_1[2] = 0;

  param_1[3] = 0;

  param_1[4] = 0;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  param_1[0xf] = 0;

  if (bVar9) {

    iVar5 = 1;

    lVar8 = 1;

    uVar4 = uVar2;

    do {

      iVar7 = (int)uVar4;

      if (0xd < iVar7) {

        FID_conflict__assert

                  (L"j < b2_blockSizes",L"C:\\dev\\Box2d2\\Box2D\\Common\\b2BlockAllocator.cpp",0x49

                  );

      }

      cVar6 = (char)uVar4;

      if (*(int *)(&DAT_140399f70 + (longlong)iVar7 * 4) < iVar5) {

        uVar4 = (ulonglong)(iVar7 + 1);

        cVar6 = cVar6 + '\x01';

      }

      iVar5 = iVar5 + 1;

      (&DAT_1403ff940)[lVar8] = cVar6;

      lVar8 = lVar8 + 1;

    } while (lVar8 < 0x281);

    DAT_1403ff7b5 = '\x01';

  }

  param_1[0x3210] = 0;

  *(undefined4 *)(param_1 + 0x3211) = 0;

  *(undefined4 *)(param_1 + 0x3252) = 0;

  *(undefined4 *)((longlong)param_1 + 0x192b4) = 0x10;

  *(undefined4 *)(param_1 + 0x3254) = 0xffffffff;

  *(undefined4 *)(param_1 + 0x3256) = 0;

  uVar1 = _malloc_base(0x280);

  param_1[0x3255] = uVar1;

  FUN_1402f94c0(uVar1,0,(longlong)*(int *)((longlong)param_1 + 0x192b4) * 0x28);

  iVar5 = *(int *)((longlong)param_1 + 0x192b4);

  uVar4 = uVar2;

  if (0 < iVar5 + -1) {

    do {

      uVar3 = (int)uVar4 + 1;

      *(uint *)(uVar2 + 0x18 + param_1[0x3255]) = uVar3;

      *(undefined4 *)(uVar2 + 0x24 + param_1[0x3255]) = 0xffffffff;

      iVar5 = *(int *)((longlong)param_1 + 0x192b4);

      uVar2 = uVar2 + 0x28;

      uVar4 = (ulonglong)uVar3;

    } while ((int)uVar3 < iVar5 + -1);

  }

  *(undefined4 *)(param_1[0x3255] + -0x10 + (longlong)iVar5 * 0x28) = 0xffffffff;

  *(undefined4 *)(param_1[0x3255] + -4 + (longlong)*(int *)((longlong)param_1 + 0x192b4) * 0x28) =

       0xffffffff;

  param_1[0x3257] = 0;

  *(undefined4 *)(param_1 + 0x3258) = 0;

  *(undefined4 *)(param_1 + 0x3259) = 0;

  param_1[0x325d] = 0x10;

  uVar1 = _malloc_base(0xc0);

  param_1[0x325c] = uVar1;

  param_1[0x325b] = 0x10;

  uVar1 = _malloc_base(0x40);

  param_1[0x325a] = uVar1;

  param_1[0x3261] = &PTR_vftable_1403e9750;

  param_1[0x3262] = &PTR_vftable_1403e9758;

  param_1[0x325f] = 0;

  *(undefined4 *)(param_1 + 0x3260) = 0;

  param_1[0x3263] = 0;

  param_1[0x3269] = 0;

  param_1[0x326a] = 0;

  param_1[0x3264] = 0;

  param_1[0x3265] = 0;

  param_1[0x3266] = 0;

  *(undefined4 *)((longlong)param_1 + 0x1935c) = 0x1000101;

  *(undefined1 *)(param_1 + 0x3268) = param_3;

  param_1[0x3267] = *param_2;

  *(undefined4 *)(param_1 + 0x3253) = 4;

  *(undefined4 *)(param_1 + 0x326b) = 0;

  param_1[0x3263] = param_1;

  param_1[0x326c] = 0;

  param_1[0x326d] = 0;

  param_1[0x326e] = 0;

  param_1[0x326f] = 0;

  return param_1;

}




