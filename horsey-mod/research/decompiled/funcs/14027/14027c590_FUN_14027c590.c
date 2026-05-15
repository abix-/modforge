// Address: 0x14027c590
// Ghidra name: FUN_14027c590
// ============ 0x14027c590 FUN_14027c590 (size=1335) ============


void FUN_14027c590(undefined8 param_1,undefined8 *param_2,byte *param_3,int param_4)



{

  char cVar1;

  byte *pbVar2;

  int iVar3;

  undefined8 uVar4;

  longlong lVar5;

  byte bVar6;

  byte bVar7;

  ulonglong uVar8;

  byte bVar9;

  short sVar10;

  bool bVar11;

  byte *local_res10 [2];

  undefined4 local_res20;

  

  uVar4 = FUN_140149300();

  if (((*(char *)((longlong)param_2 + 0x2a) != '\0') &&

      (*(char *)((longlong)param_2 + 0x2b) == '\0')) && (param_4 == 0x2e)) {

    local_res10[0] = (byte *)CONCAT26(local_res10[0]._6_2_,0x70200004d);

    FUN_140284590(*param_2,local_res10,6);

  }

  if (*(byte *)((longlong)param_2 + 0x5c) != *param_3) {

    FUN_14015ad00(uVar4,param_1,6,*param_3 >> 2 & 1);

    FUN_14015ad00(uVar4,param_1,4,*param_3 >> 3 & 1);

    FUN_14015ad00(uVar4,param_1,0,*param_3 >> 4 & 1);

    FUN_14015ad00(uVar4,param_1,1,*param_3 >> 5 & 1);

    FUN_14015ad00(uVar4,param_1,2,*param_3 >> 6 & 1);

    FUN_14015ad00(uVar4,param_1,3,*param_3 >> 7);

  }

  bVar9 = param_3[1];

  if (*(byte *)((longlong)param_2 + 0x5d) != bVar9) {

    bVar6 = bVar9 & 1 | 4;

    if ((bVar9 & 2) == 0) {

      bVar6 = bVar9 & 1;

    }

    bVar7 = bVar6 | 8;

    if ((bVar9 & 4) == 0) {

      bVar7 = bVar6;

    }

    bVar6 = bVar7 | 2;

    if ((bVar9 & 8) == 0) {

      bVar6 = bVar7;

    }

    FUN_14015ae90(uVar4,param_1,0,bVar6);

    if ((*(short *)(param_2 + 1) == 0x1532) && (*(short *)((longlong)param_2 + 10) == 0xa00)) {

      FUN_14015ad00(uVar4,param_1,9,param_3[1] >> 5 & 1);

      bVar9 = param_3[1] >> 4;

    }

    else {

      FUN_14015ad00(uVar4,param_1,9,param_3[1] >> 4 & 1);

      bVar9 = param_3[1] >> 5;

    }

    FUN_14015ad00(uVar4,param_1,10,bVar9 & 1);

    FUN_14015ad00(uVar4,param_1,7,param_3[1] >> 6 & 1);

    FUN_14015ad00(uVar4,param_1,8,param_3[1] >> 7);

  }

  if (*(char *)((longlong)param_2 + 0x2d) != '\0') {

    if (param_4 < 0x2c) {

      bVar9 = param_3[0xe];

      bVar11 = *(byte *)((longlong)param_2 + 0x6a) == bVar9;

    }

    else if (param_4 == 0x2c) {

      bVar9 = param_3[0x12];

      bVar11 = *(byte *)((longlong)param_2 + 0x6e) == bVar9;

    }

    else if (param_4 == 0x2e) {

      bVar9 = param_3[0x1c];

      bVar11 = *(byte *)(param_2 + 0xf) == bVar9;

    }

    else {

      if (param_4 != 0x3c) goto LAB_14027c7f1;

      bVar9 = param_3[0x2a];

      bVar11 = *(byte *)((longlong)param_2 + 0x86) == bVar9;

    }

    if (!bVar11) {

      FUN_14015ad00(uVar4,param_1,0xb,bVar9 & 1);

    }

  }

LAB_14027c7f1:

  if ((*(char *)((longlong)param_2 + 0x2a) != '\0') && (*(char *)((longlong)param_2 + 0x2b) == '\0')

     ) {

    if (param_4 == 0x1d) {

      local_res20 = 8;

      bVar6 = 4;

      bVar7 = 1;

      iVar3 = memcmp(param_3,param_3 + 0xe,2);

      bVar11 = iVar3 == 0;

      bVar9 = 2;

      lVar5 = 0x1c;

    }

    else if (param_4 == 0x22) {

      bVar11 = param_3[0xf] == 0;

      bVar9 = 1;

      local_res20 = 2;

      bVar6 = 8;

      bVar7 = 4;

      lVar5 = 0xe;

    }

    else if (param_4 == 0x2e) {

      bVar11 = param_3[0x13] == 0;

      bVar9 = 1;

      local_res20 = 2;

      bVar6 = 8;

      bVar7 = 4;

      lVar5 = 0x12;

    }

    else {

      if (param_4 != 0x2f) goto LAB_14027c95b;

      bVar11 = param_3[0x14] == 0;

      bVar9 = 1;

      local_res20 = 2;

      bVar6 = 8;

      bVar7 = 4;

      lVar5 = 0xe;

    }

    local_res10[0] = param_3 + lVar5;

    if (!bVar11) {

      *local_res10[0] = 0;

    }

    if (*(byte *)(param_2 + 6) != *local_res10[0]) {

      cVar1 = *(char *)((longlong)param_2 + 0x2d);

      FUN_14015ad00(uVar4,param_1,cVar1 + '\v',(bVar9 & *local_res10[0]) != 0);

      FUN_14015ad00(uVar4,param_1,cVar1 + '\f',(*local_res10[0] & (byte)local_res20) != 0);

      FUN_14015ad00(uVar4,param_1,cVar1 + 0xdU,(*local_res10[0] & bVar7) != 0);

      pbVar2 = local_res10[0];

      FUN_14015ad00(uVar4,param_1,(byte)(cVar1 + 0xdU) + 1,(*local_res10[0] & bVar6) != 0);

      *(byte *)(param_2 + 6) = *pbVar2;

    }

  }

LAB_14027c95b:

  sVar10 = (*(short *)(param_3 + 2) + -0x200) * 0x40;

  if (sVar10 == 0x7fc0) {

    sVar10 = 0x7fff;

  }

  else if (((sVar10 == -0x8000) && (param_4 == 0x1a)) && ((char)param_3[0x12] < '\0')) {

    sVar10 = 0x7fff;

  }

  FUN_14015aab0(uVar4,param_1,4,sVar10);

  sVar10 = (*(short *)(param_3 + 4) + -0x200) * 0x40;

  if (sVar10 == -0x8000) {

    if ((param_4 == 0x1a) && ((param_3[0x12] & 0x40) != 0)) {

      sVar10 = 0x7fff;

    }

  }

  else if (sVar10 == 0x7fc0) {

    sVar10 = 0x7fff;

  }

  FUN_14015aab0(uVar4,param_1,5,sVar10);

  FUN_14015aab0(uVar4,param_1,0,*(undefined2 *)(param_3 + 6));

  FUN_14015aab0(uVar4,param_1,1,~*(ushort *)(param_3 + 8));

  FUN_14015aab0(uVar4,param_1,2,*(undefined2 *)(param_3 + 10));

  FUN_14015aab0(uVar4,param_1,3,~*(ushort *)(param_3 + 0xc));

  uVar8 = 0x40;

  if ((ulonglong)(longlong)param_4 < 0x40) {

    uVar8 = (longlong)param_4;

  }

  FUN_1402f8e20((longlong)param_2 + 0x5c,param_3,uVar8);

  *(undefined1 *)((longlong)param_2 + 0x2b) = 0;

  return;

}




