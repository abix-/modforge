// Address: 0x14026d940
// Ghidra name: FUN_14026d940
// ============ 0x14026d940 FUN_14026d940 (size=1098) ============


void FUN_14026d940(undefined8 param_1,longlong param_2,char *param_3,int param_4)



{

  undefined4 uVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  undefined8 uVar4;

  undefined2 uVar5;

  ulonglong uVar6;

  int iVar7;

  undefined8 uVar8;

  float fVar9;

  

  uVar4 = FUN_140149300();

  if (1 < param_4) {

    if (*param_3 == '\x02') {

      FUN_14015ad00(uVar4,param_1,5,param_3[1] & 1);

    }

    else if (*param_3 == '\x04') {

      fVar9 = (float)thunk_FUN_1402e1d00(((float)(byte)param_3[1] / DAT_14030a2d0) * DAT_14039ca5c);

      FUN_14015af40(param_1,1,(int)fVar9);

    }

    else if ((0x10 < param_4) && (*param_3 == '\x01')) {

      if (*(byte *)(param_2 + 0xd) != param_3[0xd]) {

        switch(param_3[0xd] & 0xf) {

        case 1:

          uVar8 = 1;

          break;

        case 2:

          uVar8 = 3;

          break;

        case 3:

          uVar8 = 2;

          break;

        case 4:

          uVar8 = 6;

          break;

        case 5:

          uVar8 = 4;

          break;

        case 6:

          uVar8 = 0xc;

          break;

        case 7:

          uVar8 = 8;

          break;

        case 8:

          uVar8 = 9;

          break;

        default:

          uVar8 = 0;

        }

        FUN_14015ae90(uVar4,param_1,0,uVar8);

      }

      if (*(byte *)(param_2 + 0xe) != param_3[0xe]) {

        FUN_14015ad00(uVar4,param_1,0,param_3[0xe] & 1);

        FUN_14015ad00(uVar4,param_1,1,(byte)param_3[0xe] >> 1 & 1);

        FUN_14015ad00(uVar4,param_1,2,(byte)param_3[0xe] >> 3 & 1);

        FUN_14015ad00(uVar4,param_1,3,(byte)param_3[0xe] >> 4 & 1);

        FUN_14015ad00(uVar4,param_1,9,(byte)param_3[0xe] >> 6 & 1);

        FUN_14015ad00(uVar4,param_1,10,(byte)param_3[0xe] >> 7);

      }

      if (*(byte *)(param_2 + 0xf) != param_3[0xf]) {

        FUN_14015ad00(uVar4,param_1,6,(byte)param_3[0xf] >> 3 & 1);

        FUN_14015ad00(uVar4,param_1,7,(byte)param_3[0xf] >> 5 & 1);

        FUN_14015ad00(uVar4,param_1,8,(byte)param_3[0xf] >> 6 & 1);

      }

      if (*(byte *)(param_2 + 0x10) != param_3[0x10]) {

        FUN_14015ad00(uVar4,param_1,4,param_3[0x10] & 1);

        FUN_14015ad00(uVar4,param_1,0xb,(byte)param_3[0x10] >> 1 & 1);

      }

      uVar2 = DAT_14037dea8;

      uVar1 = DAT_1403053f0;

      uVar5 = 0;

      if (param_3[2] == '\x7f') {

        iVar7 = 0;

      }

      else {

        fVar9 = (float)FUN_140208370();

        iVar7 = (int)fVar9;

      }

      FUN_14015aab0(uVar4,param_1,0,iVar7);

      if (param_3[4] == '\x7f') {

        iVar7 = 0;

      }

      else {

        fVar9 = (float)FUN_140208370();

        iVar7 = (int)fVar9;

      }

      FUN_14015aab0(uVar4,param_1,1,iVar7);

      if (param_3[6] == '\x7f') {

        iVar7 = 0;

      }

      else {

        fVar9 = (float)FUN_140208370();

        iVar7 = (int)fVar9;

      }

      FUN_14015aab0(uVar4,param_1,2,iVar7);

      if (param_3[8] != '\x7f') {

        fVar9 = (float)FUN_140208370();

        uVar5 = (undefined2)(int)fVar9;

      }

      FUN_14015aab0(uVar4,param_1,3,uVar5);

      uVar3 = DAT_14037efd0;

      fVar9 = (float)FUN_140208370((*(ushort *)(param_3 + 9) & 0x3ff) - 0x200,DAT_14037efd0,

                                   DAT_14037efcc,uVar2,uVar1);

      FUN_14015aab0(uVar4,param_1,4,(int)fVar9);

      fVar9 = (float)FUN_140208370((*(ushort *)(param_3 + 0xb) & 0x3ff) - 0x200,uVar3,DAT_14037efcc,

                                   uVar2,uVar1);

      FUN_14015aab0(uVar4,param_1,5,(int)fVar9);

      uVar6 = 0x40;

      if ((ulonglong)(longlong)param_4 < 0x40) {

        uVar6 = (longlong)param_4;

      }

      FUN_1402f8e20(param_2,param_3,uVar6);

    }

  }

  return;

}




