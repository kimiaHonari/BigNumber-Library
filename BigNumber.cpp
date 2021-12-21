#include "BigNumber.h"
#include <string>
BigNumber BigNumber::fun(int size)
{
	BigNumber s;
	Node *pt=head.next;
	Node *ptr=&s.head;
	while(size--)
	{
		new Node(pt->digit,ptr);
		ptr=ptr->next;
		pt=pt->next;
		if(pt==&head)
			break;
	}
	return s;
}
BigNumber::BigNumber(const string& str )
{
	Node* ptr=&head;
	int i=0;
	if(str[0]=='-')
	{
		this->negative=1;
		i=1;
	}
	else
		this->negative=0;
	for(i;i<(str.size());i++)
	{
		new Node((str[i]-'0'),ptr);
		ptr=ptr->next;
	}


}
BigNumber::BigNumber(void)
{
	negative=0;
}
BigNumber::BigNumber(const int num)
{
	int r=num;
	if(r<0)
	{
		negative=1;
		r*=-1;
	}
	else
	{
		negative=0;
	}
	while(num)
	{
		int m=r%10;
		r/=10;
		new Node(m,&head);
	}
}
__int64 BigNumber::lengthnum()const
{
	__int64 count=0;
	Node *ptr=head.next;

	while(ptr!=&head)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}
BigNumber::BigNumber(const BigNumber& other)
{
	Node *ptr=&head;
	Node *ptr1=other.head.next;
	while( ptr1!=&other.head)
	{
		new Node(ptr1->digit,ptr);
		ptr1=ptr1->next;
		ptr=ptr->next;
	}
	negative=other.negative;
}
BigNumber::~BigNumber(void)
{
	Node *ptr=head.next;
	while(ptr != &head)
	{
		ptr=ptr->next;
		if(ptr->prev==&head)
			break;
		delete ptr->prev;
	}
}
BigNumber& BigNumber::operator=(const BigNumber& other)
{
	if(this==&other)
		return *this;
	Node *ptr=head.next;
	while(ptr != &head)
	{
		ptr=ptr->next;
		if(ptr->prev==&head)
			break;
		delete ptr->prev;

	}
	ptr=&head;
	Node *ptr1=other.head.next;
	while( ptr1!=&other.head)
	{
		new Node(ptr1->digit,ptr);
		ptr1=ptr1->next;
		ptr=ptr->next;
	}
	negative=other.negative;
	return *this;
}
istream& operator>>(istream &c, BigNumber& B)
{
	Node *ptr=&B.head;
	if(ptr->next!=&B.head)
	{
		while(ptr != &B.head)
		{
			ptr=ptr->next;
			if(ptr->prev==&B.head)
				break;
			delete ptr->prev;
		}
	}
	ptr=&B.head;
	while(1)
	{
		int ch;
		ch=getchar();
		if(ch==' ')
			break;
		if(ch=='\n')
			break;
		if(ch=='\t')
			break;
		if(ch=='-'&& !B.negative)
		{
			B.negative=1;
		}
		else
		{
			ch=ch-'0';
			new Node(ch,ptr);
			ptr=ptr->next;
		}

	}
	return c;
}
ostream& operator<<(ostream & c,const BigNumber& B)
{
	Node* ptr=B.head.next;
	if(B.negative)
		cout<<"-";
	while(ptr!=&B.head)
	{
		c<<ptr->digit;
		ptr=ptr->next;
	}
	return c;
}
bool BigNumber::operator >(const BigNumber& other)const
{
	__int64 len1=this->lengthnum();
	__int64 len2=other.lengthnum();
	if(negative == other.negative)
	{
		if(negative)
		{
			if(len1 > len2)
				return false;
			else if(len1 < len2)
				return true;
			else if(len1 == len2)
			{
				Node *ptr=head.next;
				Node* ptr1=other.head.next;
				while(ptr !=&head)
				{
					if(ptr->digit > ptr1->digit)
						return false;
					if(ptr->digit < ptr1->digit)
						return true;
					if(ptr->digit == ptr1->digit)
					{
						ptr=ptr->next;
						ptr1=ptr1->next;
					}
				}
				return false;
			}
		}
		else
		{
			if(len1 > len2)
				return true;
			if(len1 < len2)
				return false;
			if(len1 == len2)
			{
				Node *ptr=head.next;
				Node* ptr1=other.head.next;
				while(ptr !=&head)
				{
					if(ptr->digit > ptr1->digit)
						return true;
					if(ptr->digit < ptr1->digit)
						return false;
					if(ptr->digit == ptr1->digit)
					{
						ptr=ptr->next;
						ptr1=ptr1->next;
					}
				}
				return false;
			}
		}
	}
	if(negative==0 && other.negative==1)
		return true;
	if(negative==1 && other.negative==0)
		return false;

}
bool BigNumber::operator <(const BigNumber& other)const
{
	if((*this)>other)
		return false;
	if((*this)==other)
		return false;
	else
		return true;
}
bool BigNumber::operator <=(const BigNumber& other)const
{
	if((*this)==other)
		return true;
	if((*this)<other)
		return true;
	if((*this)>other)
		return false;
}
bool BigNumber::operator >=(const BigNumber& other)const
{
	if((*this)==other)
		return true;
	if((*this)<other)
		return false;
	if((*this)>other)
		return true;
}
bool BigNumber::operator ==(const BigNumber& other)const
{
	__int64 len1=this->lengthnum();
	__int64 len2=other.lengthnum();
	if(negative==other.negative)
	{
		if(len1 > len2)
			return false;
		if(len1 < len2)
			return false;
		if(len1 == len2)
		{
			Node *ptr=head.next;
			Node* ptr1=other.head.next;
			while(ptr !=&head)
			{
				if(ptr->digit > ptr1->digit)
					return false;
				if(ptr->digit < ptr1->digit)
					return false;
				if(ptr->digit == ptr1->digit)
				{
					ptr=ptr->next;
					ptr1=ptr1->next;
				}
			}
			return true;
		}
	}
	else
		return false;
}
bool BigNumber::operator !=(const BigNumber& other)const
{
	if((*this)==other)
		return false;
	else
		return true;
}
int  BigNumber::operator [](int i)const
{
	int b=i;
	Node *ptr=head.next;
	while(ptr!=&head && b--)
	{
		ptr=ptr->next;

	}
	if(b==-1)
		return ptr->digit;
	else
		return -1;
}
BigNumber BigNumber::operator()(int i,int j)const
{
	BigNumber num;
	Node* pt=&num.head;
	num.negative=negative;
	for (int s=i;s<=j;s++)
	{
		int i=(*this)[s];
		new Node(i,pt);
		pt=pt->next;
	}
	return num;
}
BigNumber BigNumber::operator+(const BigNumber& other)const
{
	BigNumber SUM;
	Node* su=&SUM.head;
	Node* ptr=head.prev;
	Node* pt=other.head.prev;
	bool flag=0;
	if(negative==other.negative)
	{
		SUM.negative=negative;
		int temp=0;

		while(ptr!=&head || pt!=&other.head)
		{
			int sum=(ptr->digit)+(pt->digit)+temp;
			temp=0;
			if(sum>=10)
			{
				int x=sum%10;
				new Node(x,su);
				temp=sum/10;
			} 
			else
			{
				new Node(sum,su);
			}
			ptr=ptr->prev;
			pt=pt->prev;
			if(pt==&other.head)
			{
				if(ptr!=&head)
				{
					while(ptr!=&head)
					{
						sum=ptr->digit+temp;
						temp=0;
						if(sum>=10)
						{
							int x=sum%10;
							new Node(x,su);
							temp=sum/10;
						} 
						else
						{
							new Node(sum,su);
						}
						ptr=ptr->prev;
					}
				}
				else
				{
					if(temp)
					{
						new Node(temp,su);
					}

				}

				break;
			}
			if(ptr==&head)
			{
				if(pt!=&other.head)
				{
					while(pt!=&other.head)
					{
						sum=pt->digit+temp;
						temp=0;
						if(sum>=10)
						{
							int x=sum%10;
							new Node(x,su);
							temp=sum/10;
						} 
						else
						{
							new Node(sum,su);
						}
						pt=pt->prev;
					}

					if(temp)
					{
						new Node(temp,su);
					}

				}
				else
				{
					if(temp)
					{
						new Node(temp,su);
					}

				}
				break;
			}
		}
		su=su->next;
		while(su!=&SUM.head)
		{
			if(su->digit==0)
			{
				su=su->next;
				delete su->prev;
			}
			else
				break;
		}
		return SUM;
	}
	/////////////////////////////////
	if((negative==1 && other.negative==0) || (negative==0 && other.negative==1))
	{
		__int64 len1=this->lengthnum();
		__int64 len2=other.lengthnum();
		BigNumber comp;
		if(len1==len2)
		{
			if((negative==1 && other.negative==0))
			{
				SUM=*this;
				
				SUM.negative=0;

				if(SUM==other)
				{
					Node *ptr1=SUM.head.next;
					while(ptr1 != &SUM.head)
					{
						ptr1=ptr1->next;
						if(ptr1->prev==&SUM.head)
							break;
						delete ptr1->prev;
					}
					new Node(0,su);
					return SUM;
				}
				else
				{
					if(SUM<other)
					{
						ptr=head.prev;
						pt=other.head.prev;
						SUM.negative=0;
					}
					else if(SUM>other)
					{
						ptr=other.head.prev;
						pt=head.prev;
						SUM.negative=1;
					}
					Node *ptr1=SUM.head.next;
					while(ptr1 != &SUM.head)
					{
						ptr1=ptr1->next;
						if(ptr1->prev==&SUM.head)
							break;
						delete ptr1->prev;
					}
					su=&SUM.head;
					int temp1=pt->digit;
					int temp2=pt->prev->digit;
					while(1)
					{
						if(temp1>ptr->digit)
						{
							new Node((temp1-ptr->digit),su);
						}
						else if(temp1==ptr->digit && (ptr->prev!= &head || ptr->prev!= &other.head))
						{
							new Node(0,su);
						}
						else
						{
							if(temp2)
								temp2-=1;
							else if(temp2==0)
							{
								flag=1;
								temp2=9;
							}
							temp1+=10;
							new Node((temp1-ptr->digit),su);
						}
						temp1=temp2;
						pt=pt->prev;
						temp2=pt->prev->digit;
						if(flag && temp2==0)
						{
							temp2=9;
						}
						else if(flag && temp2!=0)
						{
							temp2-=1;
							flag=0;
						}
						ptr=ptr->prev;
						if(pt==&head || pt==&other.head)
							break;

					}
					su=su->next;
					while(su!=&SUM.head)
					{
						if(su->digit==0)
						{
							su=su->next;
							delete su->prev;
						}
						else
							break;
					}
					return SUM;
				}
			}
			else if(other.negative==1 && negative==0)
			{
				SUM=other;
				SUM.negative=0;

				if(SUM==*this)
				{
					Node *ptr1=SUM.head.next;
					while(ptr1 != &SUM.head)
					{
						ptr1=ptr1->next;
						if(ptr1->prev==&SUM.head)
							break;
						delete ptr1->prev;
					}
					new Node(0,su);
					return SUM;
				}
				else
				{
					if(SUM<(*this))
					{
						ptr=other.head.prev;
						pt=head.prev;
						SUM.negative=0;
					}
					else if(SUM>(*this))
					{
						ptr=head.prev;
						pt=other.head.prev;
						SUM.negative=1;
					}
					Node *ptr1=SUM.head.next;
					while(ptr1 != &SUM.head)
					{
						ptr1=ptr1->next;
						if(ptr1->prev==&SUM.head)
							break;
						delete ptr1->prev;
					}
					su=&SUM.head;
					int temp1=pt->digit;
					int temp2=pt->prev->digit;
					while(1)
					{
						if(temp1>ptr->digit)
						{
							new Node((temp1-ptr->digit),su);
						}
						else if(temp1==ptr->digit && (ptr->prev!=&head || ptr->prev!=&other.head))
						{
							new Node(0,su);
						}
						else
						{
							if(temp2!=0)
								temp2-=1;
							else if(temp2==0)
							{
								flag=1;
								temp2=9;
							}
							temp1+=10;
							new Node((temp1-ptr->digit),su);
						}
						temp1=temp2;
						pt=pt->prev;
						temp2=pt->prev->digit;
						if(flag && temp2==0)
						{
							temp2=9;
						}
						else if(flag && temp2!=0)
						{
							temp2-=1;
							flag=0;
						}
						ptr=ptr->prev;
						if(pt==&head || pt==&other.head)
							break;
					}
					su=su->next;
					while(su!=&SUM.head)
					{
						if(su->digit==0)
						{
							su=su->next;
							delete su->prev;
						}
						else
							break;
					}
					return SUM;
				}
			}


		}
		else
		{
			if(len1>len2)
			{
				ptr=head.prev;
				pt=other.head.prev;
				if((negative==1 && other.negative==0))
					SUM.negative=1;
				else
					SUM.negative=0;
			}
			else if(len1<len2)
			{
				pt=head.prev;
				ptr=other.head.prev;
				if((negative==1 && other.negative==0))
					SUM.negative=0;
				else
					SUM.negative=1;
			}
			int temp1=ptr->digit;
			int temp2=ptr->prev->digit;
			while(1)
			{
				if(temp1>=pt->digit)
				{
					new Node((temp1-(pt->digit)),su);
				}
				else
				{
					if(temp2)
						temp2-=1;
					else if(temp2==0)
					{
						flag=1;
						temp2=9;
					}
					temp1+=10;
					new Node((temp1-(pt->digit)),su);
				}
				ptr=ptr->prev;
				temp1=temp2;
				temp2=ptr->prev->digit;
				if(flag && temp2==0)
				{
					temp2=9;
				}
				else if(flag && temp2 != 0)
				{
					flag=0;
					temp2-=1;
				}
				pt=pt->prev;
				if(pt==&other.head || pt==&head)
					break;
			}
			if(ptr->prev !=&other.head || ptr->prev!=&head)
				new Node(temp1,su);
			ptr=ptr->prev;
			while(1)
			{
				if(ptr==&head || ptr==&other.head)
					break;
				if(flag && ptr->digit==0)
					new Node(9,su);
				else if(flag && ptr->digit!=0)
				{
					flag=0;
					new Node((ptr->digit-1),su);
				}
				else if(flag==0)
					new Node(ptr->digit,su);
				ptr=ptr->prev;
			}
			su=su->next;
			while(su!=&SUM.head)
			{
				if(su->digit==0)
				{
					su=su->next;
					delete su->prev;
				}
				else
					break;
			}
			return SUM;
		}
	}
}
BigNumber BigNumber::operator-(const BigNumber& other)const
{
	BigNumber su=other;
	if(other.negative)
		su.negative=0;
	else
		su.negative=1;
	su=su+(*this);
	return su;
}
BigNumber BigNumber::operator+=(const BigNumber& other)
{
	(*this)=(*this)+other;
	return *this;
}
BigNumber BigNumber::operator-=(const BigNumber& other)
{
	(*this)=(*this)-other;
	return *this;
}
BigNumber BigNumber::operator*(const BigNumber& other)const
{
	__int64 len1=this->lengthnum();
	__int64 len2=other.lengthnum();
	int counter=0;
	Node* ptr=head.prev;
	Node* pt=other.head.prev;
	if(len1<len2)
	{
		pt=head.prev;
		ptr=other.head.prev;
	}
	BigNumber mult;
	new Node(0,&mult.head);
	if(this->negative!= other.negative)
		mult.negative=1;
	if(head.next->digit==0 || other.head.next->digit==0)
	{
		return mult;
	}
	BigNumber temp1;
	temp1.negative=mult.negative;
	int temp2=0;
	while(1)
	{
		int i=pt->digit;
		int b=0;
		while(b<counter)
		{
			new Node(0,&temp1.head);
			b++;
		}
		while(1)
		{

			int m=(ptr->digit *i)+temp2;
			int x=0;
			x=m%10;
			temp2=m/10;
			new Node(x,&temp1.head);	
			ptr=ptr->prev;
			if(ptr==&head || ptr==&other.head)
			{
				ptr=ptr->prev;
				if(temp2)
					new Node(temp2,&temp1.head);
				temp2=0;
				break;
			}

		}
		mult =mult+temp1;
		Node *q=temp1.head.next;
		while(q != &temp1.head)
		{
			q=q->next;
			if(q->prev==&temp1.head)
				break;
			delete q->prev;

		}
		pt=pt->prev;
		counter++;
		if(pt==&head || pt==&other.head)
			break;
	}

	return mult;

}
BigNumber BigNumber::operator*=(const BigNumber& other)
{
	(*this)=(*this)*other;
	return *this;
}
BigNumber BigNumber::operator/(const BigNumber& other)const
{
	BigNumber div;
	BigNumber r1=(*this);
	BigNumber r2=other;
	r1.negative=r2.negative=0;
	if(r1>r2)
	{
		Node *su=&div.head;
		if((negative==1 && other.negative==0) || (negative==0 && other.negative==1))
			div.negative=1;
		else
			div.negative=0;
		BigNumber y;
		BigNumber temp;
		int lenother=other.lengthnum();
		bool flag=0;
		y=r1.fun(lenother+1);
		r1.del(lenother+1);
		while(1)
		{
			for(int i=1;i<100;i++)
			{
				temp=(other*i);
				if(temp>y)
				{
					if((i-1)>=10)
					{
						int m=(i-1)%10;
						new Node(((i-1)/10),su);
						su=su->next;
						new Node(m,su);
						su=su->next;
					}
					else
					{
						new Node((i-1),su);
						su=su->next;
					}
					y-=(other*(i-1));

					while(1)
					{
						if(r1.lengthnum()==0)
						{
							flag=1;
							break;
						}
						y.append(r1,1);
						if(y<r2)
						{

							new Node(0,su);
							su=su->next;
							r1.del(1);

						}
						else
						{
							r1.del(1);
							break;
						}
					}
					break;
				}
				if(temp==y)
				{
					if(i>=10)
					{
						int m=i%10;
						new Node((i/10),su);
						su=su->next;
						new Node(m,su);
						su=su->next;
					}
					else
					{
						new Node(i,su);
						su=su->next;
					}
					y.del(y.lengthnum());
					while(1)
					{
						if(r1.lengthnum()==0)
						{
							flag=1;
							break;
						}
						y.append(r1,1);
						if(y.head.next->digit==0)
						{
							y.del(1);
							new Node(0,su);
							su=su->next;
							r1.del(1);
						}
						else if(y<r2)
						{
							new Node(0,su);
							su=su->next;
							r1.del(1);

						}
						else
						{
							r1.del(1);
							break;
						}
					}
					break;
				}

			}
			if(flag)
				break;
		}
		return div;
	}
	else if(r1<r2)
	{
		new Node(0,&div.head);
		return div;
	}
	else
	{
		new Node(1,&div.head);
		div.negative=(this->negative*negative);
		return div;
	}



}
BigNumber BigNumber::operator/=(const BigNumber& other)
{
	(*this)=(*this)/other;
	return *this;
}
BigNumber BigNumber::operator%(const BigNumber& other)const
{
	BigNumber temp=((*this)/other);
	BigNumber y=temp*other;
	temp=(*this)-y;
	return temp;
}
BigNumber BigNumber::operator%=(const BigNumber& other)
{
	(*this)=((*this)%other);
	return *this;
}
BigNumber BigNumber::operator*(const int b)const
{
	Node* ptr=head.prev;
	BigNumber mult;
	int i=b;
	if(i<0)
		i=-i;
	int temp=0;
	int m=0;
	while(ptr!=&head)
	{
		m=(i*ptr->digit)+temp;
		int x=m%10;
		temp=m/10;
		new Node(x,&mult.head);
		ptr=ptr->prev;
	}
	if(temp)
		new Node(temp,&mult.head);
	return mult;
}
BigNumber BigNumber::del(int i)
{
	Node* ptr=head.next;
	while(i--)
	{
		ptr=ptr->next;
		if(ptr->prev!=&head)
			delete ptr->prev;
		else
			break;
	}
	return *this;
}
BigNumber BigNumber::append(BigNumber &other,int i)
{
	Node* ptr=other.head.next;
	while(ptr!=&other.head && i--)
	{
		new Node(ptr->digit,head.prev);
		ptr=ptr->next;
	}
	return *this;
}
BigNumber BigNumber::operator++()
{
	BigNumber a;
	new Node(1,&a.head);
	(*this)+=a;
	return *this;
}
BigNumber BigNumber::operator++(int)
{
	BigNumber a;
	new Node(1,&a.head);
	BigNumber b=*this;
	(*this)+=a;
	return b;
}
BigNumber BigNumber::operator--()
{
	BigNumber a;
	new Node(1,&a.head);
	a.negative=1;
	(*this)+=a;
	return *this;
}
BigNumber BigNumber::operator--(int)
{

	BigNumber a;
	new Node(1,&a.head);
	a.negative=1;
	BigNumber b=*this;
	(*this)+=a;
	return b;
}

