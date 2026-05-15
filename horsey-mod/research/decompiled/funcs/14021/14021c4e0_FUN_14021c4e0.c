// Address: 0x14021c4e0
// Ghidra name: FUN_14021c4e0
// ============ 0x14021c4e0 FUN_14021c4e0 (size=250) ============


longlong FUN_14021c4e0(char *param_1)



{

  char cVar1;

  int iVar2;

  undefined1 *puVar3;

  size_t sVar4;

  longlong lVar5;

  undefined *puVar6;

  undefined1 *puVar7;

  undefined8 local_res8;

  

  puVar3 = (undefined1 *)0x0;

  local_res8 = 0;

  if ((param_1 == (char *)0x0) || (cVar1 = *param_1, cVar1 == '\0')) {

    param_1 = "C:/";

    cVar1 = 'C';

  }

  cVar1 = FUN_140190620((int)cVar1);

  if ((((cVar1 == '/') || (cVar1 == '\\')) ||

      ((((byte)(cVar1 + 0xbfU) < 0x1a && (param_1[1] == ':')) &&

       ((param_1[2] == '\\' || (puVar3 = (undefined1 *)0x0, param_1[2] == '/')))))) ||

     (puVar3 = (undefined1 *)thunk_FUN_14021c6e0(), puVar3 != (undefined1 *)0x0)) {

    sVar4 = strlen(param_1);

    puVar6 = &DAT_14039bcb9;

    if ((param_1[sVar4 - 1] != '/') && (puVar6 = &DAT_140335ba8, param_1[sVar4 - 1] == '\\')) {

      puVar6 = &DAT_14039bcb9;

    }

    puVar7 = &DAT_14039bcb9;

    if (puVar3 != (undefined1 *)0x0) {

      puVar7 = puVar3;

    }

    iVar2 = FUN_14012ee40(&local_res8,"%s%s%s",puVar7,param_1,puVar6);

    FUN_1401841e0(puVar3);

    if (-1 < iVar2) {

      lVar5 = FUN_140177d60(&DAT_140355510,local_res8);

      if (lVar5 == 0) {

        FUN_1401841e0(local_res8);

      }

      return lVar5;

    }

  }

  return 0;

}




