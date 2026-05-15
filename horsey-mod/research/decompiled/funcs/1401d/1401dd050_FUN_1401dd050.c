// Address: 0x1401dd050
// Ghidra name: FUN_1401dd050
// ============ 0x1401dd050 FUN_1401dd050 (size=490) ============


undefined8 FUN_1401dd050(longlong param_1,int *param_2)



{

  float fVar1;

  char cVar2;

  undefined4 uVar3;

  int iVar4;

  int iVar5;

  longlong lVar6;

  longlong lVar7;

  undefined8 uVar8;

  bool bVar9;

  

  lVar7 = *(longlong *)(param_1 + 0x2e0);

  lVar6 = FUN_1401841a0(1,0xc0);

  if (lVar6 != 0) {

    bVar9 = param_2[9] == 2;

    *(longlong *)(param_2 + 0x4e) = lVar6;

    uVar3 = FUN_1401e0110(*param_2);

    iVar4 = param_2[2];

    iVar5 = param_2[1];

    cVar2 = FUN_1401dd240(*(undefined8 *)(lVar7 + 0x10),lVar6,bVar9);

    fVar1 = DAT_14039ca44;

    if (cVar2 != '\0') {

      if (*param_2 == 0x13000801) {

        *(float **)(lVar6 + 0x30) = (float *)(lVar6 + 0x38);

        *(undefined4 *)(lVar6 + 0x28) = 1;

        *(float *)(lVar6 + 0x38) = fVar1 / (float)param_2[1];

        *(float *)(lVar6 + 0x3c) = fVar1 / (float)param_2[2];

        *(float *)(lVar6 + 0x40) = (float)param_2[1];

        *(float *)(lVar6 + 0x44) = (float)param_2[2];

      }

      if ((*param_2 != 0x32315659) && (*param_2 != 0x56555949)) {

        return 1;

      }

      *(undefined1 *)(lVar6 + 0x48) = 1;

      FUN_1401e0110(*param_2,param_2[1] + 1 >> 0x1f,(param_2[1] + 1) / 2,*param_2,uVar3,iVar5,iVar4)

      ;

      cVar2 = FUN_1401dd240(*(undefined8 *)(lVar7 + 0x10),lVar6 + 0x50,bVar9);

      if (cVar2 != '\0') {

        iVar4 = (param_2[2] + 1) / 2;

        iVar5 = (param_2[1] + 1) / 2;

        uVar3 = FUN_1401e0110(*param_2);

        cVar2 = FUN_1401dd240(*(undefined8 *)(lVar7 + 0x10),lVar6 + 0x78,bVar9);

        if (cVar2 != '\0') {

          *(undefined4 *)(lVar6 + 0x28) = 4;

          lVar7 = FUN_14017b8d0(param_2[6],param_2[1],param_2[2],8,uVar3,iVar5,iVar4);

          *(longlong *)(lVar6 + 0x30) = lVar7;

          if (lVar7 != 0) {

            return 1;

          }

          uVar8 = FUN_14012e850("Unsupported YUV colorspace");

          return uVar8;

        }

      }

    }

  }

  return 0;

}




