// Address: 0x1401aa890
// Ghidra name: FUN_1401aa890
// ============ 0x1401aa890 FUN_1401aa890 (size=234) ============


undefined1 * FUN_1401aa890(char *param_1)



{

  char cVar1;

  longlong lVar2;

  undefined1 *puVar3;

  undefined1 *local_res8;

  

  if (param_1 != (char *)0x0) {

    if (*param_1 == '\0') {

      return &DAT_14039bcb9;

    }

    lVar2 = FUN_1401638b0(&DAT_1403fcd94);

    if (lVar2 == 0) {

      lVar2 = FUN_1401aaee0(0,0,FUN_1401ab0c0,FUN_1401ab2f0,&LAB_1401aafe0,0);

      if (lVar2 == 0) {

        return (undefined1 *)0x0;

      }

      FUN_140163ac0(&DAT_1403fcd94,lVar2,&LAB_1401aa800);

    }

    cVar1 = FUN_1401aaff0(lVar2,param_1,&local_res8);

    if (cVar1 != '\0') {

      return local_res8;

    }

    puVar3 = (undefined1 *)FUN_14012f0d0(param_1);

    if (puVar3 != (undefined1 *)0x0) {

      FUN_1401ab100(lVar2,puVar3,puVar3,0);

      return puVar3;

    }

  }

  return (undefined1 *)0x0;

}




