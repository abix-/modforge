// Address: 0x14007fc40
// Ghidra name: FUN_14007fc40
// ============ 0x14007fc40 FUN_14007fc40 (size=2407) ============


void FUN_14007fc40(longlong param_1)



{

  int iVar1;

  float fVar2;

  longlong local_68;

  ulonglong uStack_60;

  undefined8 local_58;

  ulonglong local_50;

  

  FUN_140070f90(DAT_1403d9c18);

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403eaeb4) && (FUN_1402c7138(&DAT_1403eaeb4), DAT_1403eaeb4 == -1)) {

    local_58 = 9;

    local_50 = 0xf;

    local_68._0_1_ = s_HorseMart_14030ac40[0];

    local_68._1_1_ = s_HorseMart_14030ac40[1];

    local_68._2_1_ = s_HorseMart_14030ac40[2];

    local_68._3_1_ = s_HorseMart_14030ac40[3];

    local_68._4_1_ = s_HorseMart_14030ac40[4];

    local_68._5_1_ = s_HorseMart_14030ac40[5];

    local_68._6_1_ = s_HorseMart_14030ac40[6];

    local_68._7_1_ = s_HorseMart_14030ac40[7];

    uStack_60 = (ulonglong)(byte)s_HorseMart_14030ac40[8];

    DAT_1403eaeb0 = FUN_14006fe60(&local_68);

    _Init_thread_footer(&DAT_1403eaeb4);

  }

  iVar1 = -DAT_1403eda00;

  if (iVar1 < DAT_14030b680 + DAT_1403eda00 * 2) {

    do {

      FUN_140071ed0(DAT_1403eaeb0);

      iVar1 = iVar1 + 0x59;

    } while (iVar1 < DAT_14030b680 + DAT_1403eda00 * 2);

  }

  FUN_140071000();

  FUN_140071d20(DAT_1403eaeb0 + 1);

  FUN_140071d20(DAT_1403eaeb0 + 2);

  FUN_140071d20(DAT_1403eaeb0 + 3);

  FUN_140071d20(DAT_1403eaeb0 + 4);

  FUN_140071000();

  FUN_140086570(DAT_1403ede28);

  FUN_140086570(DAT_1403ede28);

  FUN_140086570(DAT_1403ede28);

  FUN_140086570(DAT_1403ede28);

  FUN_14008d760(&local_68,&DAT_140307a38);

  FUN_140086570(DAT_1403ede28);

  if (0xf < local_50) {

    if ((0xfff < local_50 + 1) && (0x1f < (local_68 - *(longlong *)(local_68 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  FUN_14008d760(&local_68,&DAT_140307a38);

  FUN_140086570(DAT_1403ede28);

  if (0xf < local_50) {

    if ((0xfff < local_50 + 1) && (0x1f < (local_68 - *(longlong *)(local_68 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  FUN_14008d760(&local_68,&DAT_140307a38);

  FUN_140086570(DAT_1403ede28);

  if (0xf < local_50) {

    if ((0xfff < local_50 + 1) && (0x1f < (local_68 - *(longlong *)(local_68 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  FUN_14008d760(&local_68,&DAT_140307a38);

  FUN_140086570(DAT_1403ede28);

  if (0xf < local_50) {

    if ((0xfff < local_50 + 1) && (0x1f < (local_68 - *(longlong *)(local_68 + -8)) - 8U)) {

                    /* WARNING: Subroutine does not return */

      _invoke_watson((wchar_t *)0x0,(wchar_t *)0x0,(wchar_t *)0x0,0,0);

    }

    FUN_1402c7088();

  }

  fVar2 = (float)(*(uint *)(param_1 + 0x114) ^ DAT_14039cac0);

  FUN_140072fe0(CONCAT44(fVar2 * *(float *)(param_1 + 0x110),fVar2 * *(float *)(param_1 + 0x10c)));

  FUN_1400d5d90(param_1,1);

  FUN_1400d5ff0(param_1,1);

  FUN_1400730f0();

  if (*(char *)(param_1 + 0x264) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 600));

  }

  if (*(char *)(param_1 + 0x278) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 0x26c));

  }

  if (*(char *)(param_1 + 0x28c) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 0x280));

  }

  if (*(char *)(param_1 + 0x2a0) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 0x294));

  }

  if (*(char *)(param_1 + 0x2b4) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 0x2a8));

  }

  if (*(char *)(param_1 + 0x2c8) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 700));

  }

  if (*(char *)(param_1 + 0x2dc) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 0x2d0));

  }

  if (*(char *)(param_1 + 0x2f0) != '\0') {

    FUN_140071d20(*(undefined4 *)(param_1 + 0x2e4));

  }

  FUN_1400cacd0(param_1,1);

  return;

}




