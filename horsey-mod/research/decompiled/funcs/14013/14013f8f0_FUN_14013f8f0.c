// Address: 0x14013f8f0
// Ghidra name: FUN_14013f8f0
// ============ 0x14013f8f0 FUN_14013f8f0 (size=794) ============


undefined8 FUN_14013f8f0(longlong param_1,undefined4 param_2)



{

  undefined8 uVar1;

  undefined8 uVar2;

  bool bVar3;

  bool bVar4;

  char cVar5;

  char cVar6;

  int iVar7;

  longlong lVar8;

  undefined8 *puVar9;

  longlong lVar10;

  size_t sVar11;

  char *pcVar12;

  uint uVar13;

  longlong lVar14;

  undefined8 uVar15;

  char *pcVar16;

  bool bVar17;

  char local_res8 [8];

  undefined2 local_res18 [4];

  undefined2 local_res20 [4];

  longlong local_e8 [2];

  undefined8 local_d8;

  undefined8 uStack_d0;

  char local_c8 [144];

  

  lVar14 = 0;

  local_e8[0] = 0;

  local_res8[0] = '\0';

  bVar4 = false;

  uVar15 = 0xffffffff;

  _guard_check_icall();

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","mappingString");

    return 0xffffffff;

  }

  lVar8 = FUN_140140640(param_1);

  if (lVar8 == 0) {

    FUN_14012e850("Couldn\'t parse GUID from %s",param_1);

    return 0xffffffff;

  }

  iVar7 = FUN_14012ef60(lVar8,"default");

  bVar3 = true;

  if ((iVar7 != 0) &&

     (iVar7 = FUN_14012ef60(lVar8,"xinput"), bVar3 = false, bVar4 = false, iVar7 == 0)) {

    bVar4 = true;

  }

  puVar9 = (undefined8 *)FUN_14017e0b0(&local_d8,lVar8);

  uVar1 = *puVar9;

  uVar2 = puVar9[1];

  FUN_1401841e0(lVar8);

  local_d8 = uVar1;

  uStack_d0 = uVar2;

  FUN_1401582b0(&local_d8,local_res20,local_res18,0,0);

  cVar5 = FUN_140159470(local_res20[0],local_res18[0]);

  if (((cVar5 != '\0') &&

      (lVar8 = thunk_FUN_1402c9340(param_1,"SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS"), lVar8 == 0))

     && (FUN_14012ee40(local_e8,"%shint:SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS:=1,",param_1),

        local_e8[0] != 0)) {

    param_1 = local_e8[0];

  }

  lVar10 = thunk_FUN_1402c9340(param_1,"hint:");

  lVar8 = lVar14;

  if (lVar10 == 0) {

LAB_14013fb1e:

    local_d8 = uVar1;

    uStack_d0 = uVar2;

    lVar10 = FUN_14013fc10(&local_d8,param_1,local_res8,param_2);

    if (lVar10 == 0) goto LAB_14013fbcd;

    lVar14 = lVar8;

    if (local_res8[0] == '\0') {

      lVar14 = lVar10;

      if ((!bVar3) && (lVar14 = DAT_1403fbf20, bVar4)) {

        DAT_1403fbf28 = lVar10;

      }

      DAT_1403fbf20 = lVar14;

      uVar15 = 1;

      goto LAB_14013fbcd;

    }

  }

  else {

    sVar11 = strlen("hint:");

    pcVar12 = (char *)(sVar11 + lVar10);

    cVar5 = *(char *)(sVar11 + lVar10);

    cVar6 = cVar5;

    if (cVar5 == '!') {

      pcVar16 = pcVar12 + 1;

      pcVar12 = pcVar12 + 1;

      cVar6 = *pcVar16;

    }

    uVar13 = 0;

    if (cVar6 != '\0') {

      cVar6 = *pcVar12;

      pcVar16 = local_c8;

      do {

        if (((cVar6 == ',') || (cVar6 == ':')) || (0x7e < uVar13)) break;

        pcVar12 = pcVar12 + 1;

        *pcVar16 = cVar6;

        uVar13 = uVar13 + 1;

        pcVar16 = pcVar16 + 1;

        cVar6 = *pcVar12;

      } while (cVar6 != '\0');

    }

    local_c8[(int)uVar13] = '\0';

    if ((*pcVar12 == ':') && (pcVar12[1] == '=')) {

      iVar7 = thunk_FUN_1402d89dc(pcVar12 + 2);

      bVar17 = iVar7 != 0;

    }

    else {

      bVar17 = false;

    }

    iVar7 = strcmp(local_c8,"SDL_GAMECONTROLLER_USE_GAMECUBE_LABELS");

    if (iVar7 == 0) {

      if (cVar5 != '!') {

        param_1 = FUN_14013cb80(param_1);

LAB_14013fb09:

        lVar8 = param_1;

        if (param_1 == 0) goto LAB_14013fbcd;

      }

      goto LAB_14013fb1e;

    }

    iVar7 = strcmp(local_c8,"SDL_GAMECONTROLLER_USE_BUTTON_LABELS");

    if (iVar7 == 0) {

      if (cVar5 != '!') {

        param_1 = FUN_14013cc40(param_1);

        goto LAB_14013fb09;

      }

      goto LAB_14013fb1e;

    }

    lVar8 = FUN_140142960(local_c8);

    if (lVar8 == 0) {

      lVar8 = FUN_1401796b0(local_c8);

    }

    cVar6 = FUN_1401429e0(lVar8,bVar17);

    if (cVar5 == '!') {

      cVar6 = cVar6 == '\0';

    }

    lVar8 = 0;

    if (cVar6 != '\0') goto LAB_14013fb1e;

  }

  lVar8 = lVar14;

  uVar15 = 0;

LAB_14013fbcd:

  FUN_1401841e0(local_e8[0]);

  FUN_1401841e0(lVar8);

  return uVar15;

}




