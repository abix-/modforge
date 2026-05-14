// Address: 0x140027260
// Ghidra name: FUN_140027260
// ============ 0x140027260 FUN_140027260 (size=105) ============


void FUN_140027260(undefined8 *param_1)



{

  if ((undefined8 *)param_1[0xd] != param_1) {

    FID_conflict__assert(L"sentinel.next == &sentinel",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x5b6);

  }

  if ((undefined8 *)param_1[0xc] != param_1) {

    FID_conflict__assert(L"sentinel.prev == &sentinel",L"C:\\dev\\tinyxml\\tinyxml.cpp",0x5b7);

  }

  FUN_140027900(param_1 + 8);

  FUN_140027900(param_1 + 4);

  *param_1 = TiXmlBase::vftable;

  return;

}




