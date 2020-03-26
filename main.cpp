#include <iostream>

using namespace std;

enum menjac {automatski,manuelni};
enum bojaSkoljke {plava,crvena,zelena};
enum stanjeAuta {ugasen,pokvaren,uvoznji};

class Menjac
{
private:

    int brojBrzina;
    menjac tipMenjaca;

public:

    Menjac() {brojBrzina = 1; tipMenjaca = manuelni;}
    Menjac(int x, menjac y)
    {
        if(x > 0 && x <= 6)
            brojBrzina = x;
        else
            cout<<"Auto nema vise od 6 brzina!";
        tipMenjaca = y;
    }

    Menjac(const Menjac &m)
    {
        brojBrzina = m.brojBrzina;
        tipMenjaca = m.tipMenjaca;
    }

    bool setBrzina (int x)
    {
        if(x > 0 && x <= 6)
        {
            brojBrzina = x;
            return true;
        }
        else
            return false;
    }
    void setTip (menjac y)
    {
        tipMenjaca = y;
    }

    int getBrzina()const
    {
        return brojBrzina;
    }
    string getTip()const
    {
        if(tipMenjaca == automatski)
        {
            return "automatski";

        }else if (tipMenjaca == manuelni)
        {
            return "manuelni";
        }
    }
};

class Skoljka
{
private:

    bojaSkoljke boja;

public:

    Skoljka() { boja = zelena;}
    Skoljka(bojaSkoljke b) {boja = b;}
    Skoljka(const Skoljka &s) {boja = s.boja;}

    void setSkoljka(bojaSkoljke b)
    {
        boja = b;
    }

    string getSkoljka()const
    {
        if(boja == plava)
        {
            return "plava boja";
        }else if(boja == zelena)
        {
            return "zelena boja";
        }else if(boja == crvena)
        {
            return "crvena boja";
        }
    }
};

class Auto
{
private:
    Menjac m;
    Skoljka s;
    stanjeAuta st;
    int brojBrziina;
public:

    Auto() : m(),s()
    {
        st = ugasen;
        brojBrziina = 0;
    }
    Auto(menjac menj,int brojbrz,bojaSkoljke bs,stanjeAuta sa,int brz) : m(brojbrz,menj),s(bs)
    {
        st = sa;
        brojBrziina = brz;
        if(st == ugasen || st == pokvaren)
            brojBrziina = 0;
    }
    Auto(const Auto &a) : m(a.m),s(a.s)
    {
        st = a.st;
        brojBrziina = a.brojBrziina;
        if(st == ugasen || st == pokvaren)
        {
            brojBrziina = 0;
        }

    }
    bool setBrzina(int b)
    {
        return m.setBrzina(b);
    }
    void setTipM(menjac c)
    {
        m.setTip(c);
    }
    void setBoja(bojaSkoljke bb)
    {
        s.setSkoljka(bb);
    }

    int getBrzina()const
    {
        return m.getBrzina();
    }
    string getTipM()const
    {
        return m.getTip();
    }
    string getBoja()const
    {
        return s.getSkoljka();
    }


    bool upaliAuto()
    {
        if(st == ugasen)
        {
            st = uvoznji;
            return true;
        }else
            return false;
    }
    bool ugasiAuto()
    {
        if(st == uvoznji)
        {
            st = ugasen;
            brojBrziina = 0;
            return true;
        }else
            return false;
    }
    bool pokvariAuto()
    {
        if(st == ugasen || st == uvoznji)
        {
            st = pokvaren;
            brojBrziina = 0;
            return true;
        }else
            return false;
    }
    bool popraviAuto()
    {
        if(st == pokvaren)
        {
            st = ugasen;
            brojBrziina = 0;
            return true;
        }else
            return false;
    }

    bool povecajBrzinu()
    {
        if(st == uvoznji && brojBrziina < m.getBrzina())
        {
            brojBrziina++;
            return true;
        }else
            return false;
    }
    bool smanjBrzinu()
    {
        if(st == uvoznji && brojBrziina>0)
        {
            brojBrziina--;
            return true;
        }else
            return false;
    }

    int getBrzina2()
    {
        return brojBrziina;
    }

    string getStanje()
    {
        if(st == ugasen)
            return "ugasen";
        else if(st == pokvaren)
            return "pokvaren";
        else if(st == uvoznji)
            return "u voznji";
    }
};
int main()
{

    Auto autic;
    cout<<autic.getBrzina()<<"\n"<<autic.getTipM()<<"\n"<<autic.getBoja()<<"\n"<<autic.getBrzina2()<<"\n"<<autic.getStanje()<<endl;
    autic.setBrzina(4);
    autic.setBoja(zelena);
    autic.setTipM(automatski);
    autic.upaliAuto();
    autic.povecajBrzinu();
    autic.povecajBrzinu();
    cout<<autic.getBrzina()<<"\n"<<autic.getTipM()<<"\n"<<autic.getBoja()<<"\n"<<autic.getBrzina2()<<"\n"<<autic.getStanje()<<endl;
    Auto autic2(manuelni,4,plava,uvoznji, 2);
    cout<<autic2.getBrzina()<<" "<<autic2.getTipM()<<" "<<autic2.getBoja()<<" "<<autic2.getBrzina2()<<" "<<autic2.getStanje()<<endl;
    Auto autic3(automatski,2,crvena,ugasen,4);
    Auto autic4(autic3);
    cout<<autic2.getBrzina()<<" "<<autic2.getTipM()<<" "<<autic2.getBoja()<<" "<<autic2.getBrzina2()<<" "<<autic2.getStanje()<<endl;
    return 0;
}
