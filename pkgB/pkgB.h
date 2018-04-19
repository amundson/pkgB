#ifndef PKGA_H_

class PkgA
{
  private:
    bool just_used;

  public:
    PkgA(bool just_used);
    int doit() const;
};

#endif // PKGA_H_
