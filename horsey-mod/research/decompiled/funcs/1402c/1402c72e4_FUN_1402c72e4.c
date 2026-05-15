// Address: 0x1402c72e4
// Ghidra name: FUN_1402c72e4
// ============ 0x1402c72e4 FUN_1402c72e4 (size=150) ============


ulonglong FUN_1402c72e4(longlong param_1)



{

  word *pwVar1;

  ulonglong uVar2;

  uint7 uVar3;

  longlong lVar4;

  word *pwVar5;

  

  uVar2 = 0x5a4d;

  if (IMAGE_DOS_HEADER_140000000.e_magic == (char  [2])0x5a4d) {

    lVar4 = (longlong)(int)IMAGE_DOS_HEADER_140000000.e_lfanew;

    if ((*(int *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4) == 0x4550) &&

       (uVar2 = 0x20b,

       *(short *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -4) == 0x20b)) {

      pwVar5 = (word *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 +

                       (ulonglong)

                       *(ushort *)((longlong)IMAGE_DOS_HEADER_140000000.e_res_4_ + lVar4 + -8) +

                       0x18);

      uVar2 = (ulonglong)*(ushort *)(IMAGE_DOS_HEADER_140000000.e_magic + lVar4 + 6);

      pwVar1 = pwVar5 + uVar2 * 0x14;

      for (; pwVar5 != pwVar1; pwVar5 = pwVar5 + 0x14) {

        if (((ulonglong)*(uint *)(pwVar5 + 6) <= param_1 - 0x140000000U) &&

           (uVar2 = (ulonglong)(*(int *)(pwVar5 + 4) + *(uint *)(pwVar5 + 6)),

           param_1 - 0x140000000U < uVar2)) goto LAB_1402c735a;

      }

      pwVar5 = (word *)0x0;

LAB_1402c735a:

      if (pwVar5 == (word *)0x0) {

        return uVar2 & 0xffffffffffffff00;

      }

      uVar3 = (uint7)(uVar2 >> 8);

      if (*(int *)(pwVar5 + 0x12) < 0) {

        return (ulonglong)uVar3 << 8;

      }

      return CONCAT71(uVar3,1);

    }

  }

  return uVar2 & 0xffffffffffffff00;

}




