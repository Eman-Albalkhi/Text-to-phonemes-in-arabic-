//---------------------------------------------------------------------------
#ifndef vcbH
#define vcbH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TStaticText *StaticText1;
        TStaticText *jjjj;
        TStaticText *StaticText2;
        TEdit *Edit1;
        TCheckBox *CheckBox1;
        TCheckBox *CheckBox2;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
