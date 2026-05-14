// Address: 0x1401413c0
// Ghidra name: FUN_1401413c0
// ============ 0x1401413c0 FUN_1401413c0 (size=2346) ============


void FUN_1401413c0(short *param_1,undefined8 param_2,undefined8 param_3)



{

  short sVar1;

  bool bVar2;

  bool bVar3;

  bool bVar4;

  bool bVar5;

  int iVar6;

  int iVar7;

  undefined4 uVar8;

  char *pcVar9;

  uint uVar10;

  int iVar11;

  longlong lVar12;

  int iVar13;

  undefined1 local_90 [32];

  int local_70;

  uint local_6c;

  uint local_68;

  char local_60 [40];

  

  sVar1 = param_1[6];

  local_70 = 0;

  uVar8 = 0;

  bVar4 = false;

  bVar5 = false;

  iVar6 = 4;

  bVar2 = false;

  bVar3 = false;

  iVar11 = 2;

  lVar12 = 0;

  local_6c = 0;

  local_68 = 0;

  if (sVar1 == 1) {

    lVar12 = 1;

  }

  else if (sVar1 == 2) {

    lVar12 = 2;

  }

  else if (sVar1 == 3) {

    lVar12 = 3;

  }

  else if (sVar1 == 4) {

    lVar12 = 4;

  }

  sVar1 = *param_1;

  uVar10 = (int)lVar12 + 2;

  if (sVar1 == 1) {

    FUN_14012ef10(local_90,0x20,"%s:a%d,","leftx",0);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","lefty",1);

    local_70 = 2;

    FUN_14012f120(param_2,local_90,param_3);

    uVar8 = 2;

LAB_140141618:

    bVar2 = true;

  }

  else if (sVar1 == 2) {

    FUN_14012ef10(local_90,0x20,"%s:a%d,","rightx",0);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","righty",1);

    local_70 = 2;

    FUN_14012f120(param_2,local_90,param_3);

    uVar8 = 2;

    bVar3 = true;

  }

  else if (sVar1 == 3) {

    FUN_14012ef10(local_90,0x20,"%s:a%d,","leftx",0);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","lefty",1);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","rightx",2);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","righty",3);

    local_70 = 4;

    FUN_14012f120(param_2,local_90,param_3);

    uVar8 = 4;

    bVar3 = true;

    goto LAB_140141618;

  }

  if (param_1[1] == 1) {

    local_6c = 1;

  }

  else if (param_1[1] == 2) {

    local_6c = 2;

  }

  sVar1 = param_1[2];

  if (sVar1 == 1) {

    FUN_14012ef10(local_90,0x20,"%s:a%d,","lefttrigger",uVar8);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","righttrigger",local_70 + 1);

    FUN_14012f120(param_2,local_90,param_3);

  }

  else if (sVar1 == 2) {

    bVar4 = true;

  }

  else if (sVar1 == 3) {

    FUN_14012ef10(local_90,0x20,"%s:a%d,","lefttrigger",uVar8);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:a%d,","righttrigger",local_70 + 1);

    FUN_14012f120(param_2,local_90,param_3);

    bVar5 = true;

  }

  if (param_1[3] == 1) {

    local_68 = 1;

  }

  else if (param_1[3] == 2) {

    local_68 = 2;

  }

  FUN_14012ef10(local_90,0x20,"%s:b%d,",&DAT_1403301c0,0);

  FUN_14012f120(param_2,local_90,param_3);

  FUN_14012ef10(local_90,0x20,"%s:b%d,",&DAT_1403301c4,1);

  FUN_14012f120(param_2,local_90,param_3);

  FUN_14012ef10(local_90,0x20,"%s:b%d,",&DAT_14030a29c,2);

  FUN_14012f120(param_2,local_90,param_3);

  iVar13 = 3;

  FUN_14012ef10(local_90,0x20,"%s:b%d,",&DAT_14030a2a0,3);

  FUN_14012f120(param_2,local_90,param_3);

  FUN_14012f120(param_2,"dpup:h0.1,dpdown:h0.4,dpleft:h0.8,dpright:h0.2,",param_3);

  if (bVar2) {

    iVar13 = 4;

    FUN_14012ef10(local_90,0x20,"%s:b%d,","leftstick",4);

    iVar6 = 5;

    FUN_14012f120(param_2,local_90,param_3);

  }

  if (bVar3) {

    iVar13 = iVar6;

    FUN_14012ef10(local_90,0x20,"%s:b%d,","rightstick",iVar6);

    iVar6 = iVar6 + 1;

    FUN_14012f120(param_2,local_90,param_3);

  }

  if (local_6c != 0) {

    iVar13 = iVar6;

    FUN_14012ef10(local_90,0x20,"%s:b%d,","leftshoulder",iVar6);

    iVar6 = iVar6 + 1;

    FUN_14012f120(param_2,local_90,param_3);

  }

  if (1 < local_6c) {

    iVar13 = iVar6;

    FUN_14012ef10(local_90,0x20,"%s:b%d,","rightshoulder",iVar6);

    iVar6 = iVar6 + 1;

    FUN_14012f120(param_2,local_90,param_3);

  }

  if (bVar4) {

    FUN_14012ef10(local_90,0x20,"%s:b%d,","lefttrigger",iVar6);

    FUN_14012f120(param_2,local_90,param_3);

    pcVar9 = "righttrigger";

LAB_1401419bd:

    FUN_14012ef10(local_90,0x20,"%s:b%d,",pcVar9,iVar6 + 1);

    iVar6 = iVar6 + 2;

    FUN_14012f120(param_2,local_90,param_3);

  }

  else if (bVar5) {

    if (uVar10 < 3) {

      uVar10 = 3;

    }

    FUN_14012ef10(local_60,0x20,"misc%d",uVar10,iVar13);

    FUN_14012ef10(local_90,0x20,"%s:b%d,",local_60,iVar6);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_60,0x20,"misc%d",uVar10 + 1);

    uVar10 = uVar10 + 2;

    pcVar9 = local_60;

    goto LAB_1401419bd;

  }

  if (local_68 != 0) {

    FUN_14012ef10(local_90,0x20,"%s:b%d,","paddle2",iVar6);

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:b%d,","paddle1",iVar6 + 1);

    iVar6 = iVar6 + 2;

    FUN_14012f120(param_2,local_90,param_3);

  }

  iVar13 = iVar6;

  FUN_14012ef10(local_90,0x20,"%s:b%d,","start",iVar6);

  iVar7 = iVar6 + 1;

  FUN_14012f120(param_2,local_90,param_3);

  sVar1 = param_1[4];

  if (sVar1 == 1) {

    pcVar9 = "back";

LAB_140141b49:

    iVar13 = iVar7;

    FUN_14012ef10(local_90,0x20,"%s:b%d,",pcVar9,iVar7);

    iVar7 = iVar7 + 1;

    FUN_14012f120(param_2,local_90,param_3);

  }

  else {

    if (sVar1 == 2) {

      FUN_14012ef10(local_90,0x20,"%s:b%d,",&DAT_14030dbb8,iVar7);

      iVar7 = iVar6 + 2;

      FUN_14012f120(param_2,local_90,param_3);

      pcVar9 = "guide";

      goto LAB_140141b49;

    }

    if (sVar1 == 3) {

      FUN_14012ef10(local_90,0x20,"%s:b%d,",&DAT_14030dbb8,iVar7);

      FUN_14012f120(param_2,local_90,param_3);

      FUN_14012ef10(local_90,0x20,"%s:b%d,","guide",iVar6 + 2);

      iVar7 = iVar6 + 3;

      FUN_14012f120(param_2,local_90,param_3);

      pcVar9 = "misc1";

      goto LAB_140141b49;

    }

  }

  if (1 < local_68) {

    FUN_14012ef10(local_90,0x20,"%s:b%d,","paddle4",iVar7);

    iVar13 = iVar7 + 1;

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_90,0x20,"%s:b%d,","paddle3",iVar13);

    iVar7 = iVar7 + 2;

    FUN_14012f120(param_2,local_90,param_3);

  }

  if (param_1[5] == 1) {

    pcVar9 = "touchpad";

  }

  else {

    if (param_1[5] != 2) goto LAB_140141c6f;

    FUN_14012ef10(local_90,0x20,"%s:b%d,","touchpad",iVar7);

    iVar7 = iVar7 + 1;

    FUN_14012f120(param_2,local_90,param_3);

    FUN_14012ef10(local_60,0x20,"misc%d",uVar10);

    pcVar9 = local_60;

  }

  iVar13 = iVar7;

  FUN_14012ef10(local_90,0x20,"%s:b%d,",pcVar9,iVar7);

  iVar7 = iVar7 + 1;

  FUN_14012f120(param_2,local_90,param_3);

LAB_140141c6f:

  if ((int)lVar12 != 0) {

    do {

      FUN_14012ef10(local_60,0x20,"misc%d",iVar11,iVar13);

      iVar11 = iVar11 + 1;

      iVar13 = iVar7;

      FUN_14012ef10(local_90,0x20,"%s:b%d,",local_60);

      iVar7 = iVar7 + 1;

      FUN_14012f120(param_2,local_90,param_3);

      lVar12 = lVar12 + -1;

    } while (lVar12 != 0);

  }

  return;

}




