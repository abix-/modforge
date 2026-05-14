// Address: 0x14027cca0
// Ghidra name: FUN_14027cca0
// ============ 0x14027cca0 FUN_14027cca0 (size=353) ============


undefined1 FUN_14027cca0(longlong *param_1)



{

  longlong lVar1;

  char cVar2;

  undefined1 uVar3;

  int iVar4;

  ulonglong uVar5;

  longlong lVar6;

  bool bVar7;

  undefined4 local_18;

  undefined2 local_14;

  undefined2 local_12;

  undefined1 local_10;

  undefined1 local_f;

  undefined2 local_e;

  undefined1 local_c;

  

  if ((int)param_1[7] == 1) {

    if (param_1[8] == 0) goto LAB_14027cd11;

    *(undefined4 *)(param_1 + 7) = 2;

  }

  else if ((int)param_1[7] != 2) goto LAB_14027cd11;

  lVar1 = param_1[8];

  cVar2 = *(char *)(*param_1 + 0x54);

  uVar5 = FUN_140149350();

  lVar6 = 10;

  if (cVar2 != '\0') {

    lVar6 = 0x32;

  }

  if ((ulonglong)(lVar6 + lVar1) <= uVar5) {

    param_1[8] = 0;

    *(undefined4 *)(param_1 + 7) = 0;

  }

LAB_14027cd11:

  if (((char)param_1[9] != '\0') && ((int)param_1[7] == 0)) {

    *(undefined1 *)(param_1 + 9) = 0;

    cVar2 = FUN_1402843f0();

    if (cVar2 == '\0') {

      return 0;

    }

    lVar1 = *param_1;

    local_12 = *(undefined2 *)((longlong)param_1 + 0x33);

    local_10 = *(undefined1 *)((longlong)param_1 + 0x31);

    local_14 = *(undefined2 *)((longlong)param_1 + 0x31);

    if (*(char *)(lVar1 + 0x54) == '\0') {

      local_18 = 0x9000009;

      local_14 = 0xf00;

      local_e = 0xff;

      local_c = 0xeb;

      local_f = *(undefined1 *)((longlong)param_1 + 0x32);

      iVar4 = FUN_140284670(lVar1,&local_18,0xd,FUN_14027cbf0,param_1);

      bVar7 = iVar4 == 0xd;

    }

    else {

      local_12 = 0xff;

      local_10 = 0xeb;

      local_18 = CONCAT13(*(undefined1 *)((longlong)param_1 + 0x34),

                          CONCAT12(*(undefined1 *)((longlong)param_1 + 0x33),0xf03));

      iVar4 = FUN_140284670(lVar1,&local_18,9,FUN_14027cbf0,param_1);

      bVar7 = iVar4 == 9;

    }

    if (!bVar7) {

      uVar3 = FUN_14012e850("Couldn\'t send rumble packet");

      return uVar3;

    }

    *(undefined4 *)(param_1 + 7) = 1;

  }

  return 1;

}




