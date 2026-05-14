// Address: 0x14027e0d0
// Ghidra name: FUN_14027e0d0
// ============ 0x14027e0d0 FUN_14027e0d0 (size=1050) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_14027e0d0(longlong param_1,undefined8 param_2,longlong param_3)



{

  uint uVar1;

  longlong lVar2;

  byte bVar3;

  undefined8 uVar4;

  byte bVar5;

  float fVar6;

  float fVar7;

  float local_28;

  float local_24;

  float local_20;

  

  lVar2 = *(longlong *)(param_1 + 0x70);

  uVar4 = FUN_140149300();

  if ((ulonglong)*(uint *)(param_3 + 1) != *(ulonglong *)(lVar2 + 0x10)) {

    FUN_14015ad00(uVar4,param_2,0,*(uint *)(param_3 + 1) & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,1,

                  CONCAT31((uint3)(*(uint *)(param_3 + 1) >> 9),(char)(*(uint *)(param_3 + 1) >> 1))

                  & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,2,*(uint *)(param_3 + 1) >> 2 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,3,*(uint *)(param_3 + 1) >> 3 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,9,*(uint *)(param_3 + 1) >> 0x13 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,10,*(uint *)(param_3 + 1) >> 9 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,4,*(uint *)(param_3 + 1) >> 0xe & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,6,*(uint *)(param_3 + 1) >> 6 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,5,*(byte *)(param_3 + 3) & 1);

    FUN_14015ad00(uVar4,param_2,0xb,*(uint *)(param_3 + 1) >> 4 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,7,*(uint *)(param_3 + 1) >> 0xf & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,8,*(uint *)(param_3 + 1) >> 5 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,0xc,*(uint *)(param_3 + 1) >> 7 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,0xd,*(uint *)(param_3 + 1) >> 0x11 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,0xe,*(uint *)(param_3 + 1) >> 8 & 0xffffff01);

    FUN_14015ad00(uVar4,param_2,0xf,*(uint *)(param_3 + 1) >> 0x12 & 0xffffff01);

    uVar1 = *(uint *)(param_3 + 1);

    bVar3 = (byte)(uVar1 >> 0xd) & 1;

    bVar5 = bVar3 | 4;

    if ((uVar1 >> 10 & 1) == 0) {

      bVar5 = bVar3;

    }

    bVar3 = bVar5 | 8;

    if ((uVar1 >> 0xc & 1) == 0) {

      bVar3 = bVar5;

    }

    bVar5 = bVar3 | 2;

    if ((uVar1 >> 0xb & 1) == 0) {

      bVar5 = bVar3;

    }

    FUN_14015ae90(uVar4,param_2,0,bVar5);

    *(ulonglong *)(lVar2 + 0x10) = (ulonglong)*(uint *)(param_3 + 1);

  }

  FUN_14015aab0(uVar4,param_2,4,(*(short *)(param_3 + 5) + -0x4000) * 2);

  FUN_14015aab0(uVar4,param_2,5,(*(short *)(param_3 + 7) + -0x4000) * 2);

  FUN_14015aab0(uVar4,param_2,0,*(undefined2 *)(param_3 + 9));

  FUN_14015aab0(uVar4,param_2,1,-*(short *)(param_3 + 0xb));

  FUN_14015aab0(uVar4,param_2,2,*(undefined2 *)(param_3 + 0xd));

  FUN_14015aab0(uVar4,param_2,3,-*(short *)(param_3 + 0xf));

  local_20 = DAT_14037f684;

  fVar7 = DAT_14037f67c;

  if (*(char *)(lVar2 + 1) != '\0') {

    if (*(int *)(param_3 + 0x1d) != *(int *)(lVar2 + 4)) {

      *(longlong *)(lVar2 + 8) =

           *(longlong *)(lVar2 + 8) +

           (ulonglong)(uint)(*(int *)(param_3 + 0x1d) - *(int *)(lVar2 + 4)) * 1000;

      local_28 = (float)(int)*(short *)(param_3 + 0x27) * fVar7 * local_20;

      local_24 = (float)(int)*(short *)(param_3 + 0x2b) * fVar7 * local_20;

      local_20 = (float)-(int)*(short *)(param_3 + 0x29) * fVar7 * local_20;

      FUN_14015afd0(uVar4,param_2,2,*(undefined8 *)(lVar2 + 8),&local_28,3);

      fVar6 = (float)(int)*(short *)(param_3 + 0x21) * fVar7;

      local_28 = (fVar6 + fVar6) * _DAT_1403553cc;

      fVar6 = (float)(int)*(short *)(param_3 + 0x25) * fVar7;

      local_24 = (fVar6 + fVar6) * _DAT_1403553cc;

      fVar7 = (float)-(int)*(short *)(param_3 + 0x23) * fVar7;

      local_20 = (fVar7 + fVar7) * _DAT_1403553cc;

      FUN_14015afd0(uVar4,param_2,1,*(undefined8 *)(lVar2 + 8),&local_28,3);

      *(undefined4 *)(lVar2 + 4) = *(undefined4 *)(param_3 + 0x1d);

    }

  }

  return;

}




