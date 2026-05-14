// Address: 0x14006bc00
// Ghidra name: FUN_14006bc00
// ============ 0x14006bc00 FUN_14006bc00 (size=1637) ============


void FUN_14006bc00(longlong param_1)



{

  longlong lVar1;

  float fVar2;

  float fVar3;

  int iVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  undefined8 in_stack_ffffffffffffff58;

  undefined4 uVar8;

  ulonglong local_88 [16];

  

  uVar8 = (undefined4)((ulonglong)in_stack_ffffffffffffff58 >> 0x20);

  if (*(char *)(param_1 + 700) != '\0') {

    FUN_14006c270();

    return;

  }

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403eac34) && (FUN_1402c7138(&DAT_1403eac34), DAT_1403eac34 == -1)) {

    local_88[1] = 0;

    local_88[2] = 3;

    local_88[3] = 0xf;

    local_88[0] = (ulonglong)(uint3)DAT_14030a1ec;

    DAT_1403eac30 = FUN_14006fe60(local_88);

    _Init_thread_footer(&DAT_1403eac34);

  }

  FUN_140070f90(DAT_1403d93a8);

  if (*(int *)(param_1 + 0x2b8) != 0) {

    if (*(int *)(param_1 + 0x2b8) != 1) goto LAB_14006bdcc;

    FUN_140072fe0(CONCAT44(DAT_140307a54,DAT_140303fe4));

    (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x48))();

    FUN_1400730f0();

    FUN_140071000();

    FUN_140071000();

    FUN_140071000();

  }

  FUN_140071000();

LAB_14006bdcc:

  FUN_140072040(DAT_14030b680 + DAT_1403eda00,DAT_1403eda04,DAT_14030b684,DAT_140303758,

                (float)(DAT_14030b680 + DAT_1403eda00),(float)(DAT_1403eda04 + DAT_14030b684),

                CONCAT44(uVar8,(float)((0xf0 - DAT_1403eda04) - DAT_14030b684)),

                (float)(DAT_1403eda04 + DAT_14030b684),DAT_1403d9408);

  FUN_140086570(DAT_1403ede30);

  FUN_140071d20(DAT_1403eac30 + 8);

  FUN_140071d20(DAT_1403eac30 + 3);

  uVar8 = DAT_1403d9374;

  if (*(int *)(param_1 + 0xdc) == 7) {

    uVar8 = DAT_1403d937c;

  }

  FUN_140072640(uVar8);

  FUN_140071d20(DAT_1403eac30 + 4);

  uVar8 = DAT_1403d9374;

  if (*(int *)(param_1 + 0xdc) == 8) {

    uVar8 = DAT_1403d937c;

  }

  FUN_140072640(uVar8);

  FUN_140071d20(DAT_1403eac30 + 5);

  uVar8 = DAT_1403d9374;

  if (*(int *)(param_1 + 0xdc) == 9) {

    uVar8 = DAT_1403d937c;

  }

  FUN_140072640(uVar8);

  FUN_140071d20(DAT_1403eac30 + 6);

  uVar8 = DAT_1403d9374;

  if (*(int *)(param_1 + 0xdc) == 10) {

    uVar8 = DAT_1403d937c;

  }

  FUN_140072640(uVar8);

  FUN_140071d20(DAT_1403eac30 + 7);

  FUN_1400727d0();

  fVar5 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar5 * *(float *)(param_1 + 0x110),fVar5 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5ff0(param_1,0xffffffff);

  fVar5 = DAT_140303354;

  if (*(int *)(param_1 + 0xdc) == 0xb) {

    iVar4 = 0xb;

  }

  else {

    iVar4 = 9;

    if (*(int *)(param_1 + 0xd8) == 0xb) {

      iVar4 = 10;

    }

  }

  FUN_140071ed0(iVar4 + DAT_1403eac30,

                *(float *)(*(longlong *)(param_1 + 0x60) + 0x4ac) * DAT_140303354,

                *(float *)(*(longlong *)(param_1 + 0x60) + 0x4b0) * DAT_140303354,DAT_140303354,0);

  fVar3 = DAT_140303fb8;

  FUN_140071ed0(DAT_1403eac30);

  fVar2 = DAT_14030374c;

  fVar6 = DAT_1403033a0;

  if (DAT_1403033a0 < (float)(DAT_14030b680 + DAT_1403eda00) * fVar5) {

    do {

      FUN_140071ed0(DAT_1403eac30 + 1);

      fVar6 = fVar6 + fVar2;

    } while (fVar6 < (float)(DAT_14030b680 + DAT_1403eda00) * fVar5);

  }

  fVar6 = DAT_14030562c;

  fVar7 = DAT_14030338c;

  if (DAT_14030338c < (float)(DAT_14030b684 + DAT_1403eda04) * fVar5) {

    do {

      FUN_140071ed0(DAT_1403eac30 + 2,fVar6 - fVar7,fVar7 + fVar3,fVar5,0);

      fVar7 = fVar7 + fVar2;

    } while (fVar7 < (float)(DAT_14030b684 + DAT_1403eda04) * fVar5);

  }

  lVar1 = *(longlong *)(param_1 + 0x60);

  if (*(char *)(lVar1 + 0x53d) != '\0') {

    FUN_140071ed0(*(undefined4 *)(lVar1 + 0x50c),*(float *)(lVar1 + 0x514) * fVar5,

                  *(float *)(lVar1 + 0x518) * fVar5,fVar5,0);

  }

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,0);

  FUN_1400730f0();

  FUN_1400cacd0(param_1,1);

  return;

}




