// Address: 0x14027d570
// Ghidra name: FUN_14027d570
// ============ 0x14027d570 FUN_14027d570 (size=1761) ============


void FUN_14027d570(longlong param_1,longlong param_2,char *param_3,int param_4)



{

  byte bVar1;

  uint uVar2;

  undefined8 uVar3;

  undefined4 uVar4;

  undefined4 uVar5;

  undefined8 uVar6;

  undefined8 uVar7;

  uint uVar8;

  undefined2 uVar9;

  uint uVar10;

  ulonglong uVar11;

  int iVar12;

  undefined4 uVar13;

  float fVar14;

  undefined4 uVar15;

  undefined8 in_stack_ffffffffffffff58;

  undefined4 uVar16;

  float local_78;

  float local_74;

  float local_70;

  

  uVar16 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);

  uVar6 = FUN_140149300();

  uVar4 = DAT_14037dea8;

  uVar13 = DAT_1403053f0;

  if ((*param_3 == '\a') || (*param_3 == '\0')) {

    uVar9 = 0;

    if (param_3[1] == -0x80) {

      iVar12 = 0;

    }

    else {

      fVar14 = (float)FUN_140208370();

      iVar12 = (int)fVar14;

    }

    FUN_14015aab0(uVar6,param_1,0,iVar12);

    if (param_3[2] == -0x80) {

      iVar12 = 0;

    }

    else {

      fVar14 = (float)FUN_140208370();

      iVar12 = (int)fVar14;

    }

    FUN_14015aab0(uVar6,param_1,1,iVar12);

    if (param_3[3] == -0x80) {

      iVar12 = 0;

    }

    else {

      fVar14 = (float)FUN_140208370();

      iVar12 = (int)fVar14;

    }

    FUN_14015aab0(uVar6,param_1,2,iVar12);

    if (param_3[4] != -0x80) {

      fVar14 = (float)FUN_140208370();

      uVar9 = (undefined2)(int)fVar14;

    }

    FUN_14015aab0(uVar6,param_1,3,uVar9);

    if (*(byte *)(param_2 + 5) != param_3[5]) {

      switch(param_3[5] & 0xf) {

      case 0:

        uVar7 = 1;

        break;

      case 1:

        uVar7 = 3;

        break;

      case 2:

        uVar7 = 2;

        break;

      case 3:

        uVar7 = 6;

        break;

      case 4:

        uVar7 = 4;

        break;

      case 5:

        uVar7 = 0xc;

        break;

      case 6:

        uVar7 = 8;

        break;

      case 7:

        uVar7 = 9;

        break;

      default:

        uVar7 = 0;

      }

      FUN_14015ae90(uVar6,param_1,0,uVar7);

      FUN_14015ad00(uVar6,param_1,0,(byte)param_3[5] >> 4 & 1);

      FUN_14015ad00(uVar6,param_1,1,(byte)param_3[5] >> 5 & 1);

      FUN_14015ad00(uVar6,param_1,0xb,(byte)param_3[5] >> 6 & 1);

      FUN_14015ad00(uVar6,param_1,2,(byte)param_3[5] >> 7);

    }

    if (*(byte *)(param_2 + 6) != param_3[6]) {

      FUN_14015ad00(uVar6,param_1,3,param_3[6] & 1);

      FUN_14015ad00(uVar6,param_1,0xe,(byte)param_3[6] >> 1 & 1);

      FUN_14015ad00(uVar6,param_1,9,(byte)param_3[6] >> 2 & 1);

      FUN_14015ad00(uVar6,param_1,10,(byte)param_3[6] >> 3 & 1);

      FUN_14015ad00(uVar6,param_1,4,(byte)param_3[6] >> 6 & 1);

      FUN_14015ad00(uVar6,param_1,6,(byte)param_3[6] >> 7);

    }

    if (*(byte *)(param_2 + 7) != param_3[7]) {

      FUN_14015ad00(uVar6,param_1,5,param_3[7] & 1);

      FUN_14015ad00(uVar6,param_1,7,(byte)param_3[7] >> 1 & 1);

      FUN_14015ad00(uVar6,param_1,8,(byte)param_3[7] >> 2 & 1);

      FUN_14015ad00(uVar6,param_1,0xf,(byte)param_3[7] >> 3 & 1);

      FUN_14015ad00(uVar6,param_1,0x10,(byte)param_3[7] >> 4 & 1);

      FUN_14015ad00(uVar6,param_1,0x11,(byte)param_3[7] >> 5 & 1);

      FUN_14015ad00(uVar6,param_1,0xc,(byte)param_3[7] >> 6 & 1);

      FUN_14015ad00(uVar6,param_1,0xd,(byte)param_3[7] >> 7);

    }

    if ((*(char *)(param_2 + 0x60) == '\0') && (*(char *)(param_2 + 0x61) != '\0')) {

      uVar7 = CONCAT44(uVar16,(uint)(byte)param_3[0x27]);

      FUN_14012ef10(&local_78,0x12,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",param_3[0x26],uVar7,param_3[0x28]

                    ,param_3[0x29],param_3[0x2a],param_3[0x2b]);

      uVar16 = (undefined4)((ulonglong)uVar7 >> 0x20);

      _guard_check_icall();

      uVar7 = FUN_14012f0d0(&local_78);

      *(undefined8 *)(param_1 + 0x18) = uVar7;

      *(undefined1 *)(param_2 + 0x61) = 0;

    }

    FUN_14015aab0(uVar6,param_1,5,(ushort)(byte)param_3[8] * 0x101 + -0x8000);

    FUN_14015aab0(uVar6,param_1,4,(ushort)(byte)param_3[9] * 0x101 + -0x8000);

    fVar14 = DAT_14039ca80;

    uVar15 = DAT_14037fd88;

    uVar5 = DAT_14037fd84;

    uVar2 = *(uint *)(param_2 + 0x48);

    uVar10 = (uint)*(ushort *)(param_3 + 10);

    uVar7 = CONCAT44(uVar16,DAT_14037fd84);

    *(uint *)(param_2 + 0x48) = uVar10;

    uVar8 = uVar10 - uVar2;

    if (uVar10 <= uVar2) {

      uVar8 = uVar8 + 0x10000;

    }

    *(longlong *)(param_2 + 0x40) = *(longlong *)(param_2 + 0x40) + (ulonglong)uVar8;

    *(longlong *)(param_2 + 0x58) = *(longlong *)(param_2 + 0x58) + *(longlong *)(param_2 + 0x50);

    uVar3 = *(undefined8 *)(param_2 + 0x58);

    local_74 = (float)FUN_140276c60((float)(int)*(short *)(param_3 + 0xc) * fVar14,uVar4,uVar13,

                                    uVar15,uVar7);

    local_70 = (float)FUN_140276c60((float)(int)*(short *)(param_3 + 0xe) * fVar14,uVar4,uVar13,

                                    uVar15,uVar5);

    local_78 = (float)FUN_140276c60((float)(int)*(short *)(param_3 + 0x10) * fVar14,uVar4,uVar13,

                                    uVar15,uVar5);

    FUN_14015afd0(uVar6,param_1,2,uVar3,&local_78,3);

    local_70 = (float)(int)*(short *)(param_3 + 0x12) * DAT_14037ef9c;

    local_74 = (float)(int)-((int)(short)((ushort)(byte)param_3[0x15] << 8) |

                            (uint)(byte)param_3[0x14]) * DAT_14037ef9c;

    local_78 = (float)(int)*(short *)(param_3 + 0x16) * DAT_14037ef9c;

    FUN_14015afd0(uVar6,param_1,1,uVar3,&local_78,3);

    bVar1 = param_3[0x18];

    if (*(byte *)(param_2 + 0x18) != bVar1) {

      uVar13 = 3;

      if (((bVar1 & 0x10) == 0) && (uVar13 = 4, *(char *)(param_2 + 0x60) != '\0')) {

        uVar13 = 1;

      }

      FUN_14015af40(param_1,uVar13,(bVar1 & 0xf) * '\n');

    }

    uVar11 = 0x40;

    if ((ulonglong)(longlong)param_4 < 0x40) {

      uVar11 = (longlong)param_4;

    }

    FUN_1402f8e20(param_2,param_3,uVar11);

  }

  return;

}




