// Address: 0x14021c2d0
// Ghidra name: FUN_14021c2d0
// ============ 0x14021c2d0 FUN_14021c2d0 (size=214) ============


longlong FUN_14021c2d0(char *param_1)



{

  bool bVar1;

  int iVar2;

  size_t sVar3;

  longlong lVar4;

  longlong lVar5;

  longlong lVar6;

  undefined *puVar7;

  longlong local_res8;

  

  lVar6 = 0;

  local_res8 = 0;

  if (param_1 == (char *)0x0) {

    lVar5 = FUN_140178aa0();

    lVar4 = lVar6;

    if (lVar5 != 0) {

      lVar4 = FUN_14012f0d0(lVar5);

    }

  }

  else {

    sVar3 = strlen(param_1);

    if (sVar3 == 0) {

      lVar4 = FUN_14012f0d0(&DAT_14039bcb9);

    }

    else {

      if ((param_1[sVar3 - 1] == '/') || (bVar1 = true, param_1[sVar3 - 1] == '\\')) {

        bVar1 = false;

      }

      puVar7 = &DAT_14039bcb9;

      if (bVar1) {

        puVar7 = &DAT_140335ba8;

      }

      iVar2 = FUN_14012ee40(&local_res8,&DAT_14031bb40,param_1,puVar7);

      lVar4 = local_res8;

      if (iVar2 == -1) {

        return 0;

      }

    }

  }

  local_res8 = lVar4;

  if ((local_res8 != 0) && (lVar6 = FUN_140177d60(&DAT_140355450,local_res8), lVar6 == 0)) {

    FUN_1401841e0(local_res8);

  }

  return lVar6;

}




