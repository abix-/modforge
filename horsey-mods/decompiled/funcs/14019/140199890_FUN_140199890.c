// Address: 0x140199890
// Ghidra name: FUN_140199890
// ============ 0x140199890 FUN_140199890 (size=121) ============


longlong FUN_140199890(longlong param_1,longlong param_2)



{

  longlong lVar1;

  int iVar2;

  longlong lVar3;

  

  iVar2 = 0;

  if (0 < *(int *)(param_1 + 8)) {

    lVar3 = 0;

    do {

      lVar1 = *(longlong *)(lVar3 + *(longlong *)(param_1 + 0x10));

      if (*(longlong *)(lVar1 + 8) == param_2) {

        return lVar1;

      }

      if ((*(longlong *)(lVar1 + 0x1028) != 0) &&

         (lVar1 = FUN_140199890(*(longlong *)(lVar1 + 0x1028),param_2), lVar1 != 0)) {

        return lVar1;

      }

      iVar2 = iVar2 + 1;

      lVar3 = lVar3 + 8;

    } while (iVar2 < *(int *)(param_1 + 8));

  }

  return 0;

}




