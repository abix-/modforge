// Address: 0x14013c130
// Ghidra name: FUN_14013c130
// ============ 0x14013c130 FUN_14013c130 (size=437) ============


longlong FUN_14013c130(longlong param_1,undefined4 *param_2)



{

  char cVar1;

  char *_Str;

  bool bVar2;

  size_t sVar3;

  size_t sVar4;

  size_t sVar5;

  longlong lVar6;

  char *pcVar7;

  undefined1 *puVar8;

  longlong lVar9;

  undefined4 local_58;

  undefined4 uStack_54;

  undefined4 uStack_50;

  undefined4 uStack_4c;

  char local_48 [48];

  

  bVar2 = false;

  pcVar7 = (char *)0x0;

  _guard_check_icall();

  local_58 = *param_2;

  uStack_54 = param_2[1];

  uStack_50 = param_2[2];

  uStack_4c = param_2[3];

  FUN_14017e050(&local_58,local_48,0x21);

  sVar3 = strlen(*(char **)(param_1 + 0x18));

  sVar4 = strlen(*(char **)(param_1 + 0x10));

  sVar5 = strlen(local_48);

  lVar9 = sVar3 + sVar4 + sVar5 + 3;

  lVar6 = thunk_FUN_1402c9340(*(undefined8 *)(param_1 + 0x18),"platform:");

  if (lVar6 == 0) {

    pcVar7 = *(char **)(param_1 + 0x18);

    bVar2 = true;

    sVar3 = strlen(pcVar7);

    cVar1 = pcVar7[sVar3 - 1];

    pcVar7 = (char *)FUN_14017e2c0();

    sVar3 = strlen(pcVar7);

    sVar4 = strlen("platform:");

    lVar6 = lVar9 + 1;

    if (cVar1 == ',') {

      lVar6 = lVar9;

    }

    lVar9 = lVar6 + 1 + sVar3 + sVar4;

  }

  lVar6 = FUN_1401841f0(lVar9);

  if (lVar6 != 0) {

    FUN_14012ef10(lVar6,lVar9,"%s,%s,%s",local_48,*(undefined8 *)(param_1 + 0x10),

                  *(undefined8 *)(param_1 + 0x18));

    if (bVar2) {

      _Str = *(char **)(param_1 + 0x18);

      sVar3 = strlen(_Str);

      if (_Str[sVar3 - 1] != ',') {

        FUN_14012f120(lVar6,&DAT_140331a5c,lVar9);

      }

      FUN_14012f120(lVar6,"platform:",lVar9);

      FUN_14012f120(lVar6,pcVar7,lVar9);

      FUN_14012f120(lVar6,&DAT_140331a5c,lVar9);

    }

    lVar9 = thunk_FUN_1402c9340(lVar6,"platform:");

    if ((lVar9 != 0) &&

       (puVar8 = (undefined1 *)thunk_FUN_1402c9340(lVar9 + 1,"platform:"),

       puVar8 != (undefined1 *)0x0)) {

      *puVar8 = 0;

    }

  }

  return lVar6;

}




