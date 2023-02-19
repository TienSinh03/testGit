package quachXuanNam.bai06;
/**
 * 
 * @author Nam
 *
 */

import java.text.NumberFormat;
import java.util.Locale;

public class Account {
	private long accountNumber;
	private String name;
	private double balance;
	private final double RATE = 0.035;

	/**
	 * constructor mặc định (số tài khoản = 999999, tên tài khoản = “chưa xác định”,
	 * số dư = 50000)
	 */
	public Account() {
		this(999999, "chưa xác định", 50000);
	}

	/**
	 * constructor đầy đủ tham số: Trong trường hợp giá trị tham số không hợp lệ thì
	 * gán giá trị mặc định cho thuộc tính tương ứng (dữ liệu gán là hợp lệ khi số
	 * tài khoản >0, tên tài khoản khác rỗng, số dư >=50000).
	 * 
	 * @param accNumber : số tài khoản mặc định 0
	 * @param name      : tên tài khoản mặc định "chưa xác định"
	 * @param balance   : số dư mặc định 50000
	 */
	public Account(long accNumber, String name, double balance) {
		if (accNumber > 0) {
			this.accountNumber = accNumber;
		}else
			this.accountNumber = 0;
		if (name.isEmpty())
			this.name = "chưa xác định";
		else
			this.name = name;
		if (balance >= 50000)
			this.balance = balance;
		else
			this.balance = 50000;
	}

	/**
	 * constructor có hai tham số
	 * 
	 * @param accNumber : số tài khoản
	 * @param name      : tên tài khoản
	 * @param balance   : số dư mặc định 50000
	 */
	public Account(long accNumber, String name) {
		this(accNumber, name, 50000);
	}

	// <<property get>>
	public long getAccountNumber() {
		return accountNumber;
	}

	public double getBalance() {
		return balance;
	}

	// <<other methods>>
	/**
	 * cho phép gởi thêm số tiền amount vào tài khoản, hàm trả về true nếu gởi thành công (amount>0)
	 * @param amount : số tiền gửi thêm
	 * @return
	 */
	public boolean deposit(double amount) {
		if (amount > 0) {
			this.balance+=amount;
			return true;
		}
		return false;
	}

	/**
	 * cho phép rút số tiền amount từ tài khoản, hàm trả về true nếu rút tiền thành công (amount>0 và amount+fee <= balance)
	 * 
	 * @param amount : số tiền gửi thêm
	 * @param fee : phí rút tiền
	 * @return
	 */
	public boolean withdraw(double amount, double fee) {
		if(amount > 0 && amount + fee <= this.balance) {
			this.balance-=(amount+fee);
			return true;
		}
		return false;
	}

	/**
	 * tính tiền lãi, balance = balance + balance * RATE.
	 */
	public void addInterest() {
		this.balance += this.balance * RATE;
	}

	/**
	 * chuyển một khoản tiền amount từ account này sang account kia, trả về true nếu chuyển thành công.
	 * 
	 * @param acc2 : tài khoản bên chuyển tiền
	 * @param amount : số tiền chuyển
	 * @return
	 */
	public boolean transfer(Account acc2, double amount) {
		if(amount > 0 && this.balance > amount) {
			this.withdraw(amount, 0);
			acc2.deposit(amount);
			return true;
		}
		return false;
	}
	/**
	 * Kiểu định dạng tiêu đề: "%12s \t %-30s %14s \t %s",Số tài khoản, Tên tài khoản, Số dư, Tỉ lệ lời
	 * @return
	 */
	public static String inTieuDe() {
		return String.format("%12s \t %-30s %14s \t %s","Số tài khoản", "Tên tài khoản", "Số dư", "Tỉ lệ lời");
	}
	/**
	 * trả về chuỗi chứa toàn bộ thông tin tài khoản, yêu cầu định dạng kiểu tiền tệ
	 */
	public String toString() {
		Locale local = new Locale("vi", "vn");
		NumberFormat formater = NumberFormat.getCurrencyInstance(local);
		String str = formater.format(this.balance);
		return String.format("%12d \t %-30s %14s \t %.2f", this.accountNumber, this.name, str, this.RATE);
	}
}
