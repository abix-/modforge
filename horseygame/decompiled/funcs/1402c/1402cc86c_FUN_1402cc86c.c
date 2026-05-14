// Address: 0x1402cc86c
// Ghidra name: FUN_1402cc86c
// ============ 0x1402cc86c FUN_1402cc86c (size=136) ============


undefined8 FUN_1402cc86c(int *param_1)



{

  int iVar1;

  longlong lVar2;

  int iVar3;

  longlong lVar4;

  

  iVar3 = 0;

  if (0 < *param_1) {

    lVar4 = 0;

    do {

      iVar1 = param_1[1];

      lVar2 = FUN_1402c8e50();

      if (*(int *)(lVar2 + lVar4 + 4 + (longlong)iVar1) == 0) {

        lVar2 = 0;

      }

      else {

        iVar1 = param_1[1];

        lVar2 = FUN_1402c8e50();

        iVar1 = *(int *)(lVar2 + lVar4 + 4 + (longlong)iVar1);

        lVar2 = FUN_1402c8e50();

        lVar2 = lVar2 + iVar1;

      }

      iVar1 = __std_type_info_compare(lVar2 + 8,0x1403e9850);

      if (iVar1 == 0) {

        return 1;

      }

      iVar3 = iVar3 + 1;

      lVar4 = lVar4 + 0x14;

    } while (iVar3 < *param_1);

  }

  return 0;

}




