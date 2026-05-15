// Address: 0x140190080
// Ghidra name: FUN_140190080
// ============ 0x140190080 FUN_140190080 (size=183) ============


longlong FUN_140190080(ulonglong param_1,ulonglong param_2)



{

  longlong lVar1;

  ulonglong uVar2;

  longlong lVar3;

  ulonglong uVar4;

  ulonglong uVar5;

  

  uVar2 = 8;

  if (7 < param_1) {

    uVar2 = param_1;

  }

  uVar4 = uVar2 - param_2 % uVar2;

  if (((uVar2 <= ~param_2) && (7 < ~(param_2 + uVar2))) &&

     (uVar5 = param_2 + uVar2 + 8, uVar4 <= ~uVar5)) {

    lVar1 = FUN_1401841f0(uVar4 + uVar5);

    if (lVar1 != 0) {

      lVar3 = (uVar2 - (lVar1 + 8U) % uVar2) + lVar1 + 8U;

      *(longlong *)(lVar3 + -8) = lVar1;

      if (uVar4 != 0) {

        FUN_1402f94c0(param_2 + lVar3,0,uVar4);

      }

      return lVar3;

    }

  }

  return 0;

}




