// Address: 0x14017ed00
// Ghidra name: FUN_14017ed00
// ============ 0x14017ed00 FUN_14017ed00 (size=945) ============


int FUN_14017ed00(undefined8 param_1)



{

  char cVar1;

  int iVar2;

  int iVar3;

  undefined1 *puVar4;

  char *_Str1;

  longlong lVar5;

  undefined8 uVar6;

  FILE *pFVar7;

  longlong lVar8;

  bool bVar9;

  int local_res18 [2];

  char local_1d8 [32];

  undefined8 local_1b8;

  char *local_1b0;

  undefined4 local_1a8;

  undefined4 local_1a4;

  char *local_1a0;

  undefined4 local_198;

  undefined4 local_194;

  char *local_190;

  undefined4 local_188;

  undefined4 local_184;

  char *local_180;

  undefined4 local_178;

  undefined4 local_174;

  char *local_170;

  undefined8 local_168;

  longlong local_160;

  char *local_158;

  undefined1 *local_150;

  undefined8 local_148;

  undefined8 *local_140;

  undefined8 local_138;

  undefined1 local_128 [256];

  

  local_1a4 = 1;

  local_1b8 = 0;

  local_1b0 = "Retry";

  puVar4 = local_128;

  local_1a8 = 0;

  local_1a0 = "Break";

  local_198 = 0;

  local_190 = "Abort";

  iVar3 = 2;

  local_194 = 2;

  local_180 = "Ignore";

  local_188 = 2;

  local_170 = "Always Ignore";

  local_184 = 3;

  local_178 = 1;

  local_174 = 4;

  iVar2 = FUN_14017f240(local_128,0x100,param_1);

  if (iVar2 < 0x100) {

LAB_14017edf5:

    if (iVar2 < 0) {

      bVar9 = puVar4 == local_128;

      goto LAB_14017f084;

    }

  }

  else if ((longlong)iVar2 != -1) {

    lVar5 = (longlong)iVar2 + 1;

    puVar4 = (undefined1 *)FUN_1401841f0(lVar5);

    if (puVar4 != (undefined1 *)0x0) {

      iVar2 = FUN_14017f240(puVar4,lVar5,param_1);

      goto LAB_14017edf5;

    }

    puVar4 = local_128;

  }

  FUN_14017f420("\n\n%s\n\n",puVar4);

  _Str1 = (char *)FUN_140142960("SDL_ASSERT");

  if (_Str1 != (char *)0x0) {

    if (puVar4 != local_128) {

      FUN_1401841e0(puVar4);

    }

    iVar3 = strcmp(_Str1,"abort");

    if (iVar3 == 0) {

      return 2;

    }

    iVar3 = strcmp(_Str1,"break");

    if (iVar3 == 0) {

      return 1;

    }

    iVar3 = strcmp(_Str1,"retry");

    if (iVar3 == 0) {

      return 0;

    }

    iVar3 = strcmp(_Str1,"ignore");

    if (iVar3 == 0) {

      return 3;

    }

    iVar3 = strcmp(_Str1,"always_ignore");

    if (iVar3 != 0) {

      return 2;

    }

    return 4;

  }

  lVar5 = FUN_14016dcb0();

  if (lVar5 != 0) {

    if (*(char *)(lVar5 + 0x5d) == '\0') {

      lVar5 = 0;

    }

    else {

      FUN_14016f4f0(lVar5);

    }

  }

  local_168 = 0x20;

  local_158 = "Assertion Failed";

  local_140 = &local_1b8;

  local_148 = 5;

  local_138 = 0;

  local_160 = lVar5;

  local_150 = puVar4;

  cVar1 = FUN_1401726a0(&local_168,local_res18);

  if (cVar1 == '\0') {

    uVar6 = FUN_1402e16a0(2);

    FUN_140023ee0(uVar6,"Abort/Break/Retry/Ignore/AlwaysIgnore? [abriA] : ");

    pFVar7 = (FILE *)FUN_1402e16a0(2);

    fflush(pFVar7);

    uVar6 = FUN_1402e16a0(0);

    lVar8 = thunk_FUN_1402e1b18(local_1d8,0x20,uVar6);

    while( true ) {

      if ((lVar8 == 0) || (iVar2 = strncmp(local_1d8,"a",1), iVar2 == 0)) goto LAB_14017f070;

      iVar2 = strncmp(local_1d8,"b",1);

      if (iVar2 == 0) break;

      iVar2 = strncmp(local_1d8,"r",1);

      if (iVar2 == 0) {

        iVar3 = 0;

        goto LAB_14017f070;

      }

      iVar2 = strncmp(local_1d8,"i",1);

      if (iVar2 == 0) {

        iVar3 = 3;

        goto LAB_14017f070;

      }

      iVar2 = strncmp(local_1d8,"A",1);

      if (iVar2 == 0) {

        iVar3 = 4;

        goto LAB_14017f070;

      }

      uVar6 = FUN_1402e16a0(2);

      FUN_140023ee0(uVar6,"Abort/Break/Retry/Ignore/AlwaysIgnore? [abriA] : ");

      pFVar7 = (FILE *)FUN_1402e16a0(2);

      fflush(pFVar7);

      uVar6 = FUN_1402e16a0(0);

      lVar8 = thunk_FUN_1402e1b18(local_1d8,0x20,uVar6);

    }

    iVar3 = 1;

  }

  else {

    iVar3 = local_res18[0];

    if (local_res18[0] == -1) {

      iVar3 = 3;

    }

  }

LAB_14017f070:

  if (lVar5 != 0) {

    FUN_140170180(lVar5);

  }

  bVar9 = puVar4 == local_128;

LAB_14017f084:

  if (!bVar9) {

    FUN_1401841e0(puVar4);

  }

  return iVar3;

}




